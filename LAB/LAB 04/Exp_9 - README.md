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

## How to Compile

```bash
gcc pattern_matching.c -o pattern_matching
