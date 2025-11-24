# 📖 Overview
This C program implements a B-Tree, a self-balancing tree data structure optimized for systems that read and write large blocks of data. It supports insertion, deletion, and traversal of keys while maintaining balance across nodes. The program allows users to dynamically insert and delete keys, printing the state of the B-Tree after each operation.

# ⚙️ Usage
- Compile with: `gcc -o btree btree.c`
- Run: `./btree`
- Input the number of elements to insert and then enter each element.
- The program inserts keys into the B-Tree and prints the in-order traversal.
- Input the number of elements to delete and specify each key to remove.
- After each deletion, the program prints the updated traversal of the B-Tree.

Example:
    Enter number of elements to insert: 7
    Enter 7 elements:
      10 20 5 6 12 30 7
    
    B-Tree after insertion:
      5 6 7 10 12 20 30
    
    How many elements do you want to delete? 2
    
    Enter element to delete: 6
    
    B-Tree after deleting 6:
      5 7 10 12 20 30
    
    Enter element to delete: 20
    
    B-Tree after deleting 20:
      5 7 10 12 30

# ⏳ Time Complexity
- Search, insert, and delete operations run in O( log n ), where n is the number of keys, as the B-Tree maintains balanced height.

# 💾 Space Complexity
- Stores keys and pointers with O( n ) space.
- Dynamic node allocation adjusts to data size and tree branching.

# 🧩 Examples
    Input:
        Insert: 15 10 20 8 12 18 25
        Delete: 10 25
    
    Output:
        B-Tree after insertion:
          8 10 12 15 18 20 25
        
        B-Tree after deleting 10:
          8 12 15 18 20 25
        
        B-Tree after deleting 25:
          8 12 15 18 20


---
This implementation demonstrates the efficient handling of sorted data using B-Trees, widely applied in databases and file systems to optimize large-scale data operations.








