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

## Notes

* The comparison is approximate because values are evaluated at a single input size.
* Exponential functions may overflow for large inputs depending on system architecture.

Provide the next code whenever you're ready, and I’ll add or extend the README accordingly.
