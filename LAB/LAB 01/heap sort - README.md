# Heap Sort Implementation in C

This project provides a simple implementation of the Heap Sort algorithm. It builds a max heap from the input array and then sorts the elements by repeatedly extracting the largest value.

## Overview

The code:

- Reads `n` elements from the user  
- Builds a max heap using `heapify()`  
- Applies Heap Sort to sort the array in ascending order  
- Prints the sorted result  

Heap Sort is an in-place, comparison-based sorting algorithm with a time complexity of `O(n log n)`.

## Functions

### `heapify(arr, n, i)`
Ensures that the subtree rooted at index `i` follows the max-heap property.  
It compares a node with its children and swaps if needed, then continues recursively.

### `heapSort(arr, n)`
1. Builds a max heap from the unsorted array.  
2. Swaps the root (max element) with the last element.  
3. Shrinks the heap and restores heap property until the array is sorted.

## Compilation

Use GCC or any C compiler:

```bash
gcc heapsort.c -o heapsort
