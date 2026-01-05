# 📖 Overview
This C program implements an optimized Quick Sort algorithm that uses the median-of-three method for choosing a pivot and switches to Insertion Sort for small subarrays. This hybrid approach improves performance by reducing worst-case scenarios and overhead on small partitions.

# ⚙️ Usage
- Compile using: `gcc -o optimized_quicksort optimized_quicksort.c`
- Run the executable: `./optimized_quicksort`
- Input the number of elements and then input the integers.
- The program sorts the array in ascending order using the hybrid Quick Sort method and prints the sorted array.

    Example:
  
        Enter number of elements: 8
  
        Enter 8 integers:
          24 97 40 67 88 85 15 63
  
        Sorted array in ascending order:
          15 24 40 63 67 85 88 97

# ⏳ Time Complexity
- Average case: O( n log n ) due to divide-and-conquer Quick Sort.
- Worst case: reduced from  O( n^2 ) by median-of-three pivot selection.
- Insertion sort on small partitions is O( k^2 ), with k≤10, reducing overhead.

# 💾 Space Complexity
- In-place sorting uses O( log n ) space for recursion stack.
- No extra significant auxiliary space.

# 🧩 Examples
    Input:
    
      Enter number of elements: 5
      Enter 5 integers:
        50 23 9 18 61
    
    Output:
    
      Sorted array in ascending order:
        9 18 23 50 61

---
This enhanced Quick Sort balances efficiency and performance through pivot optimization and insertion sort on small segments.
