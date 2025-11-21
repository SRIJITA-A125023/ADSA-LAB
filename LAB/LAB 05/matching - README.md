# Greedy Bipartite Graph Matching in C

This program performs a simple greedy matching on a bipartite graph. It takes a set of edges between two partitions and selects pairs step by step, avoiding conflicts with already matched nodes.

## Overview

The graph consists of:
- A left partition with `nLeft` nodes
- A right partition with `nRight` nodes
- A list of `e` edges connecting nodes between the two partitions

The algorithm scans edges in the given order and includes an edge in the matching only if both endpoints are currently unmatched.

## Features

- Accepts up to 100 left nodes, 100 right nodes, and 1000 edges.
- Performs a straightforward greedy matching.
- Prints step-by-step decisions for each edge.
- Shows the full matching state after each iteration.
- Displays the final set of matched pairs.

## How to Compile

Use any C compiler. For example, with GCC:

```bash
gcc matching.c -o matching
