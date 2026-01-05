# 📖 Overview
This C program demonstrates both recursive and iterative implementations of binary search. It searches for a specified key in a sorted integer array and returns the position of the key if found, or indicates that the key is not present.

# ⚙️ Usage
- Compile with: `gcc -o binary_search binary_search.c`
- Run the program: `./binary_search`
- Input the number of elements, then enter the integers in ascending order.
- Enter the key to search.
- The program outputs the position of the key found by recursive and iterative searches or states if the key is not found.

Example input:

    Enter the number of elements: 5
    
    Enter 5 integers in ascending order:
        1 3 5 7 9
    
    Enter the key to search: 7

# ⏳ Time Complexity
- Both recursive and iterative binary search run in O( log n ) time, where \(n\) is the number of elements.

# 💾 Space Complexity
- Iterative version uses \(O(1)\) space.
- Recursive version uses O( log n ) space due to recursion stack.

# 🧩 Examples
    Example output for the above input:
        Recursive Search: Key 7 found at position 4
        Iterative Search: Key 7 found at position 4
    
    For a key not in the array:
        Recursive Search: Key 4 not found
        Iterative Search: Key 4 not found

---
This program clearly contrasts recursive and iterative approaches to binary search in sorted arrays.
