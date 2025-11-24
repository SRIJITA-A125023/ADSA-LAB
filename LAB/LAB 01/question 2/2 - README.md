# Algorithm Growth Comparison – README

This project contains a C program that evaluates and compares the growth of several mathematical functions by computing their values at a large input size and sorting them in increasing order. It is intended as a simple tool to study how different asymptotic functions behave relative to each other.

## Overview

The program defines twelve functions involving logarithmic, polynomial, root, exponential, and mixed expressions. It evaluates each function at `n = 102573` and then uses `qsort` to sort them based on their computed values.

## Features

* Computes values for a wide variety of growth functions
* Uses a struct-based approach to store and sort function results
* Outputs an ordered list showing which functions grow fastest and slowest
* Demonstrates practical use of `qsort` with a custom comparator

## How It Works

1. Each mathematical function is implemented as a separate function.
2. A `Function` struct stores the display name and computed value.
3. All functions are evaluated at the same `n`.
4. The results are sorted with `qsort`.
5. The sorted results are printed.

## Usage

Compile the program using a C compiler such as GCC:

```bash
gcc program.c -lm -o growth_compare
```

Run the executable:

```bash
./growth_compare
```

The output will show all functions in increasing order of growth.

## Example Output

```
Functions in increasing order of growth (approximate for n=102573):
...
```

Individual values will vary based on system and math library precision.

## Time Complexity

* Each function evaluation runs in constant time.
* Total evaluations: 12
* Sorting with `qsort`: O(k log k), where k = number of functions (12)
* Overall runtime: O(1) for practical purposes.

## Space Complexity

* Memory usage is constant: only 12 structs plus standard stack usage
* Overall memory usage: O(1)

## Additional Module: Binary vs Ternary Search

This section documents the second program, which compares the number of comparisons performed by Binary Search and Ternary Search.

### Overview

The program reads a sorted array from the user, performs both search techniques on the same input, and prints the index of the found element along with the total comparisons made.

### How It Works

1. The user enters the number of elements and the sorted array.
2. The user enters the key to search.
3. The binary search function runs and counts comparisons.
4. The ternary search function runs and counts comparisons.
5. The program prints results and comparison counts.

### Usage

Compile the program:

```bash
gcc search_compare.c -o search_compare
```

Run:

```bash
./search_compare
```

Provide input when prompted.

### Example Input

```
Enter number of elements: 5
Enter sorted elements: 1 4 7 9 15
Enter element to search: 9
```

### Example Output

```
Binary Search: Found at index 3
Ternary Search: Found at index 3

Number of Comparisons:
Binary Search Comparisons = 2
Ternary Search Comparisons = 3
```

Results vary depending on input.

### Time Complexity

**Binary Search**

* Worst case: O(log n)
* Comparisons grow with log base 2

**Ternary Search**

* Worst case: O(log₃ n)
* Slightly fewer levels than binary search but more comparisons per step

In practice, binary search often performs better due to fewer comparisons inside each iteration.

### Space Complexity

Both algorithms run in constant space:

* Only a few integer variables
* No recursion or additional memory
* Overall: O(1)

## Notes

* Ternary search does not offer real advantages on arrays. Binary search is usually faster in practice.
* Inputs must be sorted for both algorithms to work correctly.
