# 📖 Overview
This C program implements Dijkstra's algorithm to find the shortest paths from a source vertex to all other vertices in a weighted graph represented by an adjacency matrix. It calculates and prints the shortest distance and path for each vertex from the source.

# ⚙️ Usage
- Compile with: `gcc -o dijkstra dijkstra.c`
- Run the program: `./dijkstra`
- Input the number of vertices.
- Input the adjacency matrix where `0` represents no direct edge between vertices.
- Enter the source vertex from which shortest paths will be computed.
- The program outputs the shortest distances and paths from the source vertex to all other vertices.

Example input:

    Enter number of vertices: 5
    
    Enter the adjacency matrix (0 for no edge):
        0 10 0 5 0
        0 0 1 2 0
        0 0 0 0 4
        0 3 9 0 2
        7 0 6 0 0
        
    Enter the source vertex: 0

# ⏳ Time Complexity
- The implementation runs in O( n^2 ) time using an adjacency matrix and linear search for the minimum distance vertex, where \(n\) is the number of vertices.

# 💾 Space Complexity
- Uses O( n^2 ) space to store the adjacency matrix and O( n ) for arrays to track distances, visited vertices, and parents.

# 🧩 Examples

    Output for above input:
    
    Shortest distances and paths from source vertex 0:
    
      Vertex 0: 
          Distance = 0, Path = 0
      Vertex 1: 
          Distance = 8, Path = 0 -> 3 -> 1
      Vertex 2: 
          Distance = 9, Path = 0 -> 3 -> 1 -> 2
      Vertex 3: 
          Distance = 5, Path = 0 -> 3
      Vertex 4: 
          Distance = 7, Path = 0 -> 3 -> 4

---
This implementation provides a straightforward and educational approach to Dijkstra’s algorithm for shortest path computation in weighted graphs.


