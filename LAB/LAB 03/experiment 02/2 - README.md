# 📖 Overview
This C program implements a Binary Search Tree (BST) with insertion and three types of tree traversals: Inorder, Preorder, and Postorder. Users input elements to create the BST and then choose which traversal order to display. The Inorder traversal outputs the elements in sorted order.

# ⚙️ Usage
- Compile with: `gcc -o bst_traversal bst_traversal.c`
- Run: `./bst_traversal`
- Input the number of elements and then the elements themselves.
- Choose the traversal method to display:
  - `1` for Inorder (sorted order)
  - `2` for Preorder
  - `3` for Postorder
- The program displays the elements in the chosen traversal order.

Example:

    Enter number of elements: 5
    
    Enter 5 integers: 10 5 15 3 7
    
    Choose traversal to display sorted output:
    
          Inorder (Sorted Order)
          Preorder
          Postorder
          
    Enter your choice: 1
    
    Traversal Result: 3 5 7 10 15


# ⏳ Time Complexity
- Insertion: Average case O( log n) , worst case O( n ) for skewed tree.
- Traversal: O( n ) to visit all nodes.

# 💾 Space Complexity
- O( n ) for the tree storage.
- Recursion stack space can be O( h ), where h is tree height.

# 🧩 Examples
    Input:
    
        Enter number of elements: 7
        Enter 7 integers: 8 3 10 1 6 14 4
        Enter your choice: 2
        
    Output:
        Traversal Result: 8 3 1 6 4 10 14


---
This program demonstrates fundamental BST operations and traversal orders, useful for understanding tree data structures and sorted data access.






