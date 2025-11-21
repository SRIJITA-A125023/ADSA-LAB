# Kruskal's Algorithm in C (SIF Format Input)

This project implements **Kruskal’s Minimum Spanning Tree (MST)** algorithm in C.  
The program reads graph data in **SIF format** and computes the MST using a simple **union–find** structure.

---

## Features

- Reads graph edges in **SIF format**: `U V W`
- Supports up to **100 vertices**
- Uses a basic **disjoint-set (union–find)** implementation
- Prints the edges selected for the MST
- Displays the **total cost** of the MST

---

## Input Format (SIF)

A B 4
A C 6
B C 5
...
-1 -1 -1 // to stop input


Each vertex is identified by an uppercase character.  
For example, `A` maps to index `0`, `B` to `1`, etc.

---

## How to Compile

Use GCC or any standard C compiler:

```bash
gcc kruskal.c -o kruskal

