#include <stdio.h>
#include <stdlib.h>

#define MIN_DEGREE 3  // Minimum degree (order) of the B-Tree

typedef struct BTreeNode {
    int *keys;                  // Array of keys
    int t;                      // Minimum degree
    struct BTreeNode **C;       // Array of child pointers
    int n;                      // Current number of keys
    int leaf;                   // 1 if node is leaf, else 0
} BTreeNode;

// Function declarations
BTreeNode *createNode(int t, int leaf);
void traverse(BTreeNode *root);
void insert(BTreeNode **root, int k, int t);
void delete(BTreeNode **root, int k);
void deleteNode(BTreeNode *x, int k); // <-- Added this prototype

// Create a new B-tree node
BTreeNode *createNode(int t, int leaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->t = t;
    node->leaf = leaf;
    node->keys = (int *)malloc(sizeof(int) * (2 * t - 1));
    node->C = (BTreeNode **)malloc(sizeof(BTreeNode *) * (2 * t));
    node->n = 0;
    return node;
}

// Traverse and print keys
void traverse(BTreeNode *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->C[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->C[i]);
    }
}

// Split a full child
void splitChild(BTreeNode *x, int i, BTreeNode *y) {
    int t = y->t;
    BTreeNode *z = createNode(t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }
    y->n = t - 1;

    for (int j = x->n; j >= i + 1; j--)
        x->C[j + 1] = x->C[j];
    x->C[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--)
        x->keys[j + 1] = x->keys[j];
    x->keys[i] = y->keys[t - 1];
    x->n++;
}

// Insert into non-full node
void insertNonFull(BTreeNode *x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k)
            i--;
        i++;
        if (x->C[i]->n == 2 * x->t - 1) {
            splitChild(x, i, x->C[i]);
            if (k > x->keys[i])
                i++;
        }
        insertNonFull(x->C[i], k);
    }
}

// Insert a key into the B-tree
void insert(BTreeNode **root, int k, int t) {
    BTreeNode *r = *root;
    if (r->n == 2 * t - 1) {
        BTreeNode *s = createNode(t, 0);
        s->C[0] = r;
        splitChild(s, 0, r);
        int i = 0;
        if (s->keys[0] < k)
            i++;
        insertNonFull(s->C[i], k);
        *root = s;
    } else {
        insertNonFull(r, k);
    }
}

// Get predecessor
int getPred(BTreeNode *x, int idx) {
    BTreeNode *cur = x->C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];
    return cur->keys[cur->n - 1];
}

// Get successor
int getSucc(BTreeNode *x, int idx) {
    BTreeNode *cur = x->C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];
    return cur->keys[0];
}

// Merge nodes
void merge(BTreeNode *x, int idx) {
    BTreeNode *child = x->C[idx];
    BTreeNode *sibling = x->C[idx + 1];
    int t = child->t;

    child->keys[t - 1] = x->keys[idx];
    for (int i = 0; i < sibling->n; i++)
        child->keys[i + t] = sibling->keys[i];
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++)
            child->C[i + t] = sibling->C[i];
    }
    for (int i = idx + 1; i < x->n; i++)
        x->keys[i - 1] = x->keys[i];
    for (int i = idx + 2; i <= x->n; i++)
        x->C[i - 1] = x->C[i];

    child->n += sibling->n + 1;
    x->n--;
    free(sibling);
}

// Borrow from previous sibling
void borrowFromPrev(BTreeNode *x, int idx) {
    BTreeNode *child = x->C[idx];
    BTreeNode *sibling = x->C[idx - 1];

    for (int i = child->n - 1; i >= 0; i--)
        child->keys[i + 1] = child->keys[i];
    if (!child->leaf) {
        for (int i = child->n; i >= 0; i--)
            child->C[i + 1] = child->C[i];
    }
    child->keys[0] = x->keys[idx - 1];
    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];
    x->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n++;
    sibling->n--;
}

// Borrow from next sibling
void borrowFromNext(BTreeNode *x, int idx) {
    BTreeNode *child = x->C[idx];
    BTreeNode *sibling = x->C[idx + 1];

    child->keys[child->n] = x->keys[idx];
    if (!child->leaf)
        child->C[child->n + 1] = sibling->C[0];
    x->keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; i++)
        sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; i++)
            sibling->C[i - 1] = sibling->C[i];
    }
    child->n++;
    sibling->n--;
}

// Fill a child node
void fill(BTreeNode *x, int idx) {
    if (idx != 0 && x->C[idx - 1]->n >= x->t)
        borrowFromPrev(x, idx);
    else if (idx != x->n && x->C[idx + 1]->n >= x->t)
        borrowFromNext(x, idx);
    else {
        if (idx != x->n)
            merge(x, idx);
        else
            merge(x, idx - 1);
    }
}

// Remove key from leaf
void removeFromLeaf(BTreeNode *x, int idx) {
    for (int i = idx + 1; i < x->n; i++)
        x->keys[i - 1] = x->keys[i];
    x->n--;
}

// Remove key from non-leaf node
void removeFromNonLeaf(BTreeNode *x, int idx) {
    int k = x->keys[idx];
    if (x->C[idx]->n >= x->t) {
        int pred = getPred(x, idx);
        x->keys[idx] = pred;
        deleteNode(x->C[idx], pred);
    } else if (x->C[idx + 1]->n >= x->t) {
        int succ = getSucc(x, idx);
        x->keys[idx] = succ;
        deleteNode(x->C[idx + 1], succ);
    } else {
        merge(x, idx);
        deleteNode(x->C[idx], k);
    }
}

// Delete a key from subtree
void deleteNode(BTreeNode *x, int k) {
    int idx = 0;
    while (idx < x->n && x->keys[idx] < k)
        idx++;

    if (idx < x->n && x->keys[idx] == k) {
        if (x->leaf)
            removeFromLeaf(x, idx);
        else
            removeFromNonLeaf(x, idx);
    } else {
        if (x->leaf)
            return;
        int flag = (idx == x->n);
        if (x->C[idx]->n < x->t)
            fill(x, idx);
        if (flag && idx > x->n)
            deleteNode(x->C[idx - 1], k);
        else
            deleteNode(x->C[idx], k);
    }
}

// Delete key from B-tree
void delete(BTreeNode **root, int k) {
    if (*root == NULL)
        return;
    deleteNode(*root, k);
    if ((*root)->n == 0) {
        BTreeNode *tmp = *root;
        if ((*root)->leaf)
            *root = NULL;
        else
            *root = (*root)->C[0];
        free(tmp);
    }
}

// Main program
int main() {
    BTreeNode *root = createNode(MIN_DEGREE, 1);
    int n, val, delCount, delVal;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&root, val, MIN_DEGREE);
    }

    printf("\nB-Tree after insertion:\n");
    traverse(root);
    printf("\n");

    printf("\nHow many elements do you want to delete? ");
    scanf("%d", &delCount);

    for (int i = 0; i < delCount; i++) {
        printf("Enter element to delete: "); // need to enter the digit the you want to delete not the location of the element 
        scanf("%d", &delVal);
        delete(&root, delVal);
        printf("B-Tree after deleting %d:\n", delVal);
        traverse(root);
        printf("\n");
    }

    return 0;
}
