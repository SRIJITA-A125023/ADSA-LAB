# 📖 Overview
This C program demonstrates three popular sorting algorithms: Quick Sort, Merge Sort, and Heap Sort. It allows the user to input an array of integers, select a sorting method, and outputs the array sorted in ascending order. The program highlights different algorithmic approaches for sorting.

# ⚙️ Usage
- Compile with: `gcc -o sorting sorting.c`
- Run the program: `./sorting`
- Enter the number of elements and then input the array elements.
- Choose the sorting algorithm by entering:
  - `1` for Quick Sort
  - `2` for Merge Sort
  - `3` for Heap Sort
- The program prints the sorted array.

    Example:
  
        Enter number of elements: 5
  
        Enter 5 integers: 5 3 8 1 2
        
        Choose Sorting Method:
        
            Quick Sort           
            Merge Sort            
            Heap Sort
  
        Enter your choice: 2
        
        Sorted array in ascending order:
          1 2 3 5 8

# ⏳ Time Complexity
| Algorithm  | Average Case | Worst Case    |
|------------|--------------|--------------|
| Quick Sort | O( n log n ) | O( n^2 )    |
| Merge Sort | O( n log n ) | O( n log n ) |
| Heap Sort  | O( n log n ) | O( n log n ) |

# 💾 Space Complexity
| Algorithm  | Space Complexity    |
|------------|--------------------|
| Quick Sort | O( log n ) (stack)    |
| Merge Sort | O( n ) (auxiliary array) |
| Heap Sort  | O( 1 ) (in-place)      |

# 🧩 Examples
    Input:
        Enter number of elements: 6
        Enter 6 integers: 10 7 8 9 1 5
        Enter your choice: 1
        
    Output:
        Sorted array in ascending order:
          1 5 7 8 9 10
      

---
This program offers a clear comparison of three classic sorting algorithms, useful for learning and performance evaluation.

