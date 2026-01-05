# 📖 Overview
This C program reads an undirected weighted graph in Simple Interaction Format (SIF) and computes its Minimum Spanning Tree (MST) using Prim’s algorithm. It prints each edge of the MST and the total cost. The graph vertices are assumed to be labeled with uppercase letters starting from 'A'.

# ⚙️ Usage
- Compile with: `gcc -o prims prims.c`
- Run: `./prims`
- Input the number of vertices.
- Enter edges in SIF format (e.g., `A B 4`), and end input with `-1 -1 -1`.
- The program prints the MST edges and total cost.

Example input:

      Enter number of vertices: 4
      
      Enter edges in SIF format (u v w), enter -1 -1 -1 to stop:
          A B 4
          A C 3
          B C 2
          B D 5
          C D 7
          -1 -1 -1

    Output:
    
        Edges in MST using Prim’s Algorithm:
            A - C : 3
            C - B : 2
            B - D : 5
            
        Total cost of MST (Prim’s): 10

# ⏳ Time Complexity
- Prim’s algorithm implemented with adjacency matrix and simple search runs in O( n^2 ), where n is number of vertices.

# 💾 Space Complexity
- Uses O( n^2 ) space for the adjacency matrix and O( n ) for auxiliary arrays.

# 🧩 Examples
      Input:
      
            Enter number of vertices: 5
            
            Enter edges:
                A B 2
                A C 3
                B D 4
                C D 5
                D E 1
                -1 -1 -1
          
      Output:
      
            Edges in MST using Prim’s Algorithm:
                  A - B : 2
                  A - C : 3
                  B - D : 4
                  D - E : 1
            
            Total cost of MST (Prim’s): 10

---
This program illustrates an educational approach to MST computation with easy vertex labeling and SIF input format.

