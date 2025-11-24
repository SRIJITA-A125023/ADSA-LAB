# 📖 Overview
This C program performs a greedy matching algorithm on a bipartite graph. It takes the number of nodes on the left and right sets and a list of edges between them, then iteratively tries to add edges to the matching without conflicts, outputting the matching process and final matched pairs.

# ⚙️ Usage
- Compile the program using a C compiler: `gcc -o greedy_match greedy_match.c`
- Run the executable: `./greedy_match`
- Input the number of left nodes, right nodes, and edges when prompted.
- Enter each edge as two integers representing a connection between a left node and a right node.
- The program prints the step-by-step greedy matching process and final matched pairs.

  Example input:
      5 4 8
      1 6
      1 7
      2 6
      3 7
      3 9
      4 7
      5 8
      5 9

  # ⏳ Time Complexity
- The algorithm processes each edge once.
- For each edge, it checks if nodes are unmatched in \(O(1)\).
- Overall time complexity: \(O(e)\), where \(e\) is the number of edges.

# 💾 Space Complexity
- Uses arrays sized based on the maximum number of nodes.
- Space complexity: \(O(n + m + e)\) for storing nodes and edges.

# 🧩 Examples
Running with the example input produces:
--- Greedy Matching Process ---

Considering edge (1, 6): Added to matching.
Current matching: 1-6

Considering edge (1, 7): Skipped (conflict with existing match).
Current matching: 1-6

Considering edge (2, 6): Skipped (conflict with existing match).
Current matching: 1-6

Considering edge (3, 7): Added to matching.
Current matching: 1-6, 3-7

Considering edge (3, 9): Skipped (conflict with existing match).
Current matching: 1-6, 3-7

Considering edge (4, 7): Skipped (conflict with existing match).
Current matching: 1-6, 3-7

Considering edge (5, 8): Added to matching.
Current matching: 1-6, 3-7, 5-8

Considering edge (5, 9): Skipped (conflict with existing match).
Current matching: 1-6, 3-7, 5-8

Final Matching: 

  Total matched pairs: 3
  
    1 -> 6
    3 -> 7
    5 -> 8

---
This approach provides a simple greedy method to find a maximal matching in a bipartite graph but does not guarantee the maximum matching size.
