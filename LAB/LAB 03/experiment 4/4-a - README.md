# 📖 Overview
This C program implements an AVL Tree, a self-balancing binary search tree (BST) that maintains balance during insertions and deletions to ensure \(O(\log n)\) search time. It supports insertion, deletion, and in-order traversal of elements while automatically balancing the tree using rotations.

# ⚙️ Usage
- Compile with: `gcc -o avl_tree avl_tree.c`
- Run: `./avl_tree`
- Input the number of elements to insert, then enter the elements.
- The program performs AVL insertions and prints the in-order traversal (sorted order).
- Input the number of elements to delete and then enter each deletion key.
- After each deletion, the program prints the updated tree in in-order traversal.

    Example interaction:
        Enter number of elements to insert: 5
  
        Enter the elements:
          10 20 30 40 50
  
        Inorder traversal of the AVL tree:
          10 20 30 40 50
        
        Enter number of elements to delete: 2
  
        Enter element to delete: 20
  
        Tree after deletion of 20:
          10 30 40 50
  
        Enter element to delete: 40
  
        Tree after deletion of 40:
          10 30 50

# ⏳ Time Complexity
- AVL tree operations (insertion, deletion, search) run in O( log n ) time due to automatic balancing.
- Rotations and height updates maintain efficient access.

# 💾 Space Complexity
- Requires O( n ) space for storing tree nodes.
- Recursive calls use O( log n ) stack space due to balanced tree height.

# 🧩 Examples
    Input:
        Insert elements: 15 10 20 8 12 16 25
        Delete elements: 10 25
    
    Output:
        AVL tree in-order after insertions:
        8 10 12 15 16 20 25
    
    Tree after deletion of 10:
        8 12 15 16 20 25
    
    Tree after deletion of 25:
        8 12 15 16 20

---
This program provides a robust AVL Tree implementation with dynamic balancing to maintain sorted data efficiently during insertions and deletions.
