# 📖 Overview
This C program reads an undirected weighted graph in Simple Interaction Format (SIF) and computes its Minimum Spanning Tree (MST) using Kruskal’s algorithm. It uses a union-find data structure to detect cycles, finds the MST edges with minimum weight, and prints them along with the total cost.

# ⚙️ Usage
- Compile with: `gcc -o kruskal kruskal.c`
- Run: `./kruskal`
- Input the number of vertices.
- Enter edges in SIF format (`Node1 Node2 Weight`), ending input with `-1 -1 -1`.
- The program outputs the MST edges and the total MST cost.

Example 
    Input:

      Enter number of vertices: 4
      
      Enter edges in SIF format (u v w), enter -1 -1 -1 to stop:
          A B 4
          A C 3
          B C 2
          B D 5
          C D 7
          -1 -1 -1
    
    Output:
    
      Edges in MST using Kruskal’s Algorithm:
        B - C : 2
        A - C : 3
        B - D : 5
        
      Total cost of MST (Kruskal’s): 10

# ⏳ Time Complexity
- Kruskal’s algorithm complexity is O( E log E) where E is number of edges, dominated by sorting edges.
- Here, no explicit sort is used; instead scanning all pairs results in O( V^2 * V^2) in worst case.

# 💾 Space Complexity
- Uses O( V^2 ) for adjacency matrix and O( V ) for union-find parent array.

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
    
        Edges in MST using Kruskal’s Algorithm:
            D - E : 1
            A - B : 2
            A - C : 3
            B - D : 4
        
        Total cost of MST (Kruskal’s): 10

---
This program demonstrates an easy-to-understand but unoptimized Kruskal implementation for minimum spanning tree computations using SIF input format.
