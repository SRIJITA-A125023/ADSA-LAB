# 📖 Overview
This C program implements the Floyd–Warshall algorithm to find the shortest paths between all pairs of vertices in a weighted graph. The program takes an adjacency matrix as input, where large values represent the absence of direct edges (`INF`), and outputs the matrix of shortest distances between every pair of vertices.

# ⚙️ Usage
- Compile with: `gcc -o floyd_warshall floyd_warshall.c`
- Run the executable: `./floyd_warshall`
- Input the number of vertices.
- Input the adjacency matrix where `99999` (or the defined `INF`) indicates no direct edge.
- The program outputs the shortest path matrix, displaying the shortest distances or `INF` if no path exists.

Example input:

    Enter the number of vertices: 4
    
    Enter the adjacency matrix (use 99999 for INF):
        0 3 99999 7
        8 0 2 99999
        5 99999 0 1
        2 99999 99999 0

# ⏳ Time Complexity
- The Floyd–Warshall algorithm runs in O( n^3 ) time, where n is the number of vertices.

# 💾 Space Complexity
- Uses O( n^2 ) space for the distance matrix.

# 🧩 Examples
    Sample output for the above input:
    
      All-Pairs Shortest Path Matrix:
            0 3 5 6
            7 0 2 3
            3 6 0 1
            2 5 7 0

---
This program provides a clear and efficient solution for all-pairs shortest path problems in graphs using the Floyd–Warshall algorithm.
