# Huffman Coding in C

This project implements a simple version of the Huffman coding algorithm in C. It reads an input string, calculates character frequencies, builds a Huffman tree, generates codes for each character, and produces the final encoded message.

---

## Features

- Counts character frequencies from user input  
- Builds a Huffman tree using a minimal-node-pairing approach  
- Generates prefix-free Huffman codes for all characters  
- Displays codes for each character  
- Prints the final encoded binary string  

---

## How It Works

1. You enter a text message.  
2. The program counts the frequency of every character.  
3. It builds a Huffman tree by repeatedly merging the two smallest nodes.  
4. It then generates Huffman codes by traversing the tree.  
5. Each character in the message is replaced with its code to form the final encoded output.

---

## Compilation

Compile with any standard C compiler:

```bash
gcc huffman.c -o huffman


