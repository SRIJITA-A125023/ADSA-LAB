# 📖 Overview
This code implements the Heap Sort algorithm in C, which sorts an array of integers in ascending order using a binary heap data structure. It uses the `heapify` function to maintain the max heap property and the `heapSort` function to repeatedly extract the maximum element and place it at the end of the array.

# ⚙️ Usage
- Compile the C program with a C compiler, for example: `gcc -o heapsort heapsort.c`
- Run the executable: `./heapsort`
- Input the number of elements when prompted.
- Enter the integer elements separated by spaces or new lines.
- The program outputs the sorted array in ascending order.

Example:


Enter number of elements: 5

Enter 5 elements: 4 10 3 5 1

Sorted array: 1 3 4 5 10

# ⏳ Time Complexity
- Building the max heap takes \(O(n)\) time.
- Each of the \(n-1\) removals from the heap takes \(O(\log n)\) time due to the `heapify` calls.
- Overall time complexity is \(O(n log n)\).

# 💾 Space Complexity
- The algorithm sorts in place, using only a constant amount of additional space.
- Space complexity is \(O(1)\) (ignoring input storage).

# 🧩 Examples
Input:
Enter number of elements: 6
Enter 6 elements: 12 11 13 5 6 7

Output:
Sorted array: 5 6 7 11 12 13

Input:
Enter number of elements: 4
Enter 4 elements: 20 35 15 10

Output:
Sorted array: 10 15 20 35

---
This Heap Sort implementation efficiently sorts the input array in-place using a max heap.
