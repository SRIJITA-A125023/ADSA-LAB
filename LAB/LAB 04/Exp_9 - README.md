# String Pattern Matching in C (KMP and Rabin-Karp)

This project implements two classic string searching algorithms in C:

- Knuth-Morris-Pratt (KMP)
- Rabin-Karp (Fingerprinting)

You can enter any text and pattern, choose an algorithm, and the program will print the starting index of each match.

---

## Features

- Efficient KMP search using prefix (LPS) preprocessing
- Rabin-Karp search with rolling hash
- Supports multi-character text input using `fgets`
- Clean menu-based selection
- Prints all match positions or reports if no match was found

---

## Algorithm Overview
KMP

Preprocesses pattern to create the LPS array

Time complexity: O(n + m)

Avoids rechecking characters after mismatches

Rabin-Karp

Uses rolling hash to compare pattern with text windows

Efficient for large texts or multiple pattern matches

Time complexity:

Best: O(n + m)

Worst: O(nm) due to hash collisions

---

## Example

Input

Enter the text: ABABDABACDABABCABAB
Enter the pattern to search: ABABCABAB

Choose Algorithm:
1. Knuth-Morris-Pratt (KMP)
2. Rabin-Karp (Fingerprinting)
Enter choice: 1


Output

--- Result ---
Pattern found at index 10

--- 

## How to Compile 
```bash
gcc pattern_matching.c -o pattern_matching
