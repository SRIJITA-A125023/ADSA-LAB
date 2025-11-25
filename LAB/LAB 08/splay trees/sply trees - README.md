# 📖 Overview
This C program implements a Splay Tree, a self-adjusting binary search tree that moves recently accessed elements to the root through splay operations. It supports insertion, search, deletion, and in-order traversal, providing efficient amortized access to frequently used elements by restructuring the tree dynamically.

# ⚙️ Usage
- Compile with:

       gcc -o splay_tree splay_tree.c


- Run the executable:


        ./splay_tree


- Follow the interactive menu to:
- Insert keys into the splay tree.
- Search for keys (which splays the accessed node to root if found).
- Delete keys from the tree.
- Display the keys in sorted order via in-order traversal.
- Exit the program.
- Input integer keys as prompted.

- Example interaction:


      --- Splay Tree Menu ---
      
            Insert      
            Search     
            Delete      
            Inorder Traversal
            Exit

  
      Enter choice: 1
      Enter key to insert: 10
      
      Enter choice: 1
      Enter key to insert: 20
      
      Enter choice: 2
      Enter key to search: 10
      Found and splayed to root.
      
      Enter choice: 4
      Inorder: 10 20
      
      Enter choice: 3
      Enter key to delete: 20
      Deleted if it existed.
      
      Enter choice: 4
      Inorder: 10


# ⏳ Time Complexity
- Splay tree operations have an amortized time complexity of O( log n ).
- Single operations may take up to O( n ) in worst case, but sequence of operations remain efficient due to self-adjusting property.

# 💾 Space Complexity
- Uses O( n ) space for nodes.
- Each node contains pointers for left and right children and key data.

# 🧩 Examples
      Input/operation:
            - Insert 30, 20, 40
            - Search 20 (20 moved to root)
            - Delete 30
            - Inorder traversal
            
      Output:
            Found and splayed to root.
            Deleted if it existed.
            Inorder: 20 40
            


---
This program demonstrates splay tree operations with clear, user-driven interaction to explore self-adjusting BST behavior.
