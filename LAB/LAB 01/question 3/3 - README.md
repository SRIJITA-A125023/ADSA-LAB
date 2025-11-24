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

## Additional Module: Lighter Coin Detection

This section explains the third program, which identifies a single defective coin that is lighter than the rest using a divide‑and‑compare approach.

### Overview

The program assumes all coins have the same weight except one that is slightly lighter. By splitting the set into halves and comparing their total weights, it narrows down the defective coin in logarithmic time.

### How It Works

1. The user enters the number of coins and their weights.
2. The first coin's weight is treated as the normal reference weight.
3. The `findLighterCoin` function recursively splits the range:

   * It sums the left half and right half using the `weigh` function.
   * If the left side is lighter, the defective coin is in that half.
   * If the right side is lighter, the defective coin is there.
   * If both halves match, no lighter coin exists.
4. The recursion continues until a single index remains.

### Usage

Compile the program:

```bash
gcc lighter_coin.c -o lighter_coin
```

Run:

```bash
./lighter_coin
```

Enter weights when prompted.

### Example Input

```
Enter number of coins: 6
Enter weights of 6 coins: 10 10 10 9 10 10
```

### Example Output

```
Defective lighter coin found at index 3 (weight = 9)
```

### Time Complexity

The algorithm divides the range in half at each step.

* Worst case: O(log n)
* The `weigh` function runs in O(n) in the current implementation because it sums a range of elements each time.
* Combined worst‑case time: O(n log n)

A version that uses precomputed prefix sums can reduce the weighing cost to O(1), achieving true O(log n).

### Space Complexity

* The recursion depth is O(log n)
* No additional arrays or storage
* Overall: O(log n)

## Notes

* The program assumes exactly one lighter coin or none.
* If multiple coins differ in weight, the algorithm may not behave as expected.
