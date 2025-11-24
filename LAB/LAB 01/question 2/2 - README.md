# 📖 Overview
This C program implements and compares two search algorithms: Binary Search and Ternary Search, for finding a key in a sorted integer array. It counts and displays the number of comparisons performed by each method, allowing analysis of their efficiency.

# ⚙️ Usage
- Compile with a C compiler: `gcc -o search_compare search_compare.c`
- Run the program: `./search_compare`
- Enter the number of elements and then input the sorted array elements.
- Enter the key to search in the array.
- The program outputs the index position if found and the number of comparisons done by both search algorithms.

Example input sequence:
Enter number of elements: 5
Enter sorted elements: 1 3 5 7 9
Enter element to search: 7

# ⏳ Time Complexity
- Binary Search: O(log n) — splits the search interval into 2 parts.
- Ternary Search: O(log_3 n) — splits the search interval into 3 parts.
Despite the base difference, binary search usually requires fewer comparisons in practice.

# 💾 Space Complexity
- Both algorithms use O(1) additional space, as they operate in-place with iterative loops.

# 🧩 Examples

Input:
Enter number of elements: 6
Enter sorted elements: 2 4 6 8 10 12
Enter element to search: 8

Output:
Binary Search: Found at index 3
Ternary Search: Found at index 3

Number of Comparisons:
Binary Search Comparisons = 3
Ternary Search Comparisons = 5

---
This program helps observe and compare the behavior and efficiency of binary vs ternary searching on sorted arrays.
