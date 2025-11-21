# Prim’s Algorithm (MST) in C using SIF Input Format

This project implements Prim’s Minimum Spanning Tree algorithm in C.  
The graph is entered using **SIF (Simple Interaction Format)**, where each edge is given as:

<source> <destination> <weight>


Vertices are labeled as uppercase letters (A, B, C, ...).

---

## Features

- Reads graph edges in SIF format  
- Converts vertex labels (A, B, C…) into numeric indices  
- Builds an adjacency matrix  
- Runs Prim’s algorithm starting from vertex **A**  
- Prints all edges included in the MST  
- Prints the total cost  

---

## How Input Works

You specify:
1. Number of vertices  
2. Edges in the format `U V W`  
3. Stop by entering:  -1 -1 -1




