# Longest Common Subsequence (LCS) in C

This program computes the Longest Common Subsequence between two strings using dynamic programming. It also prints one LCS sequence and lists all possible common subsequences, which may include duplicates.

---

## Features

- Computes LCS length with a DP table  
- Extracts and prints one valid LCS  
- Recursively prints all common subsequences  
- Works with strings up to 100 characters  

---

## How It Works

1. Enter two strings.
2. The program builds a DP table to find the LCS length.
3. It backtracks through the DP table to print one LCS.
4. A recursive routine prints all possible common subsequences.

---

## Compilation

```bash
gcc lcs.c -o lcs



