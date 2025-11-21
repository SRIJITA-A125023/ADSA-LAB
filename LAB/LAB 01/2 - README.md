# Binary vs Ternary Search: Comparison Program in C

This program compares binary search and ternary search on a sorted array. It reports whether the key is found and counts how many element comparisons each method performs.

## Overview

The code:

- Takes a sorted array from the user
- Searches for a target value using both binary and ternary search
- Counts comparisons made by each method
- Prints the index (if found) and the number of comparisons

This is useful for understanding how both algorithms behave on the same input.

## Features

- Simple implementation of binary and ternary search  
- Global counters for comparison operations  
- Interactive input for array and key  
- Clear output showing performance differences  

## How It Works

### Binary Search
Divides the search interval into two halves.  
Makes one comparison per loop.

### Ternary Search
Divides the interval into three parts using two midpoints.  
Makes two comparisons per loop.

Although ternary search may seem more efficient, it often performs more comparisons than binary search on integer arrays.

## Compilation

Use a C compiler like GCC.

```bash
gcc search_compare.c -o search_compare
