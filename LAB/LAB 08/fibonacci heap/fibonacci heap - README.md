# 📖 Overview
This C program implements a Fibonacci Heap, an advanced priority queue data structure offering efficient amortized operations such as insert, find minimum, extract minimum, decrease key, and delete. It supports interactive operations with a user-friendly menu, demonstrating key heap functionalities with dynamic memory management and lazy consolidation for optimal performance.

# ⚙️ Usage
- Compile the program with:
  
        gcc -o fibheap fibheap.c
  
- Run the executable:
  
        ./fibheap
  
- Use the interactive menu to:
  
      - Insert new keys into the heap.
  
      - Find and display the minimum key.
  
      - Extract and remove the minimum key.
  
      - Decrease the key of a specified node.
  
      - Delete a key from the heap.

      - Display the root list of the heap for inspection.
  
      - Exit the program.
- When prompted, enter integer keys for insertion, search or modification.

-  Example workflow:

      
      ===== Fibonacci Heap Menu =====
      
      Insert
      Find Min
      Extract Min
      Decrease Key
      Delete Key
      Display Root List
      Exit
      
      Enter choice: 1
      Enter key to insert: 10
      
      Enter choice: 1
      Enter key to insert: 5
      
      Enter choice: 2
      Minimum: 5
      
      Enter choice: 3
      Extracted Min: 5
      
      Enter choice: 6
      Root List: 10


# ⏳ Time Complexity
- Insert, find minimum, and decrease key operations run in amortized O( 1 )  time.
- Extract minimum and delete operations run in amortized O( log n ) time due to the consolidation phase.
- Marking and cascading cuts ensure heap balance and efficient decrease operations.

# 💾 Space Complexity
- The heap uses O( n ) space, where n is the number of nodes stored.
- Each node maintains multiple pointers and counters, stored dynamically.

# 🧩 Examples
    Input sequence:
        - Insert keys 15, 10, 24
        - Find minimum (outputs 10)
        - Decrease key 24 to 5
        - Extract minimum (outputs 5)
        - Display root list (shows keys remaining in root list)
    
    Expected behavior:
        - Keys are dynamically linked in circular doubly-linked lists.
        - Minimum pointer updates as keys are inserted or decreased.
        - Extracting minimum consolidates trees by degrees, maintaining structure.

---
This interactive Fibonacci Heap implementation serves as an excellent tool to study and experiment with this powerful heap data structure and its amortized performance benefits.
