# 📖 Overview
This C program reads and stores graph data in the Simple Interaction Format (SIF), representing an undirected graph. It builds an adjacency matrix from input edges, tracks node names dynamically, and prints the graph as adjacency lists with node connections.

# ⚙️ Usage
- Compile with: `gcc -o sif_graph sif_graph.c`
- Run: `./sif_graph`
- Input edges line-by-line in the format `Node1 Relation Node2`. The relation is read but not processed beyond input.
- Type `END` to finish the input.
- The program outputs the adjacency list representation of the entered undirected graph.

Example input:
   
    A pp B
    
    B pp C
    
    C pp D
    
    A pp D
    
    END

  Output:
      Graph (Adjacency List):
      
      A -> B D
      
      B -> A C
      
      C -> B D
      
      D -> C A

# ⏳ Time Complexity
- Each edge insertion runs in O( n ) when searching for node indices.
- Overall complexity depends on number of nodes n and edges e.

# 💾 Space Complexity
- Uses an adjacency matrix requiring O( n^2 ) space, n <= 100.
- Stores node names in O( n ) space.

# 🧩 Examples
    Input:
        X likes Y
        Y hates Z
        Z knows X
        END
    
    Output:
        Graph (Adjacency List):
        X -> Y Z
        Y -> X Z
        Z -> Y X


---
This simple program provides an easy way to parse and represent undirected graphs from SIF input for analysis or visualization.
