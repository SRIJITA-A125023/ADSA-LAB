# 📖 Overview
This C program demonstrates two string pattern matching algorithms: Knuth-Morris-Pratt (KMP) and Rabin-Karp. It allows users to input a text and a pattern, then choose either algorithm to find occurrences of the pattern within the text efficiently, displaying all matching indices or a not-found message.

# ⚙️ Usage
- Compile with: `gcc -o pattern_match pattern_match.c -lm`
- Run the program: `./pattern_match`
- Input the text and pattern strings when prompted.
- Choose the searching algorithm:
  - `1` for Knuth-Morris-Pratt (KMP)
  - `2` for Rabin-Karp (Fingerprinting)
- The program prints the indices where the pattern matches or indicates no match.

Example:

    Enter the text: ABABDABACDABABCABAB
    
    Enter the pattern to search: ABABCABAB
    
    Choose Algorithm:
    
        Knuth-Morris-Pratt (KMP)
        Rabin-Karp (Fingerprinting)
    
    Enter choice: 1
    
    --- Result ---
    Pattern found at index 10

# ⏳ Time Complexity
- KMP algorithm runs in O( n + m ), where n is the text length and m is the pattern length.
- Rabin-Karp runs in average O( n + m ) but worst-case can be O( nm ) due to hash collisions.

# 💾 Space Complexity
- Both use O( m ) space for auxiliary arrays or hash computations.

# 🧩 Examples

    Input:
    
        Text: HELLO WORLD HELLO
        Pattern: HELLO
        Algorithm: 2 (Rabin-Karp)
        
    Output:
    
        Pattern found at index 0
        Pattern found at index 12

---
This program provides a hands-on way to explore two fundamental pattern matching algorithms, useful in text processing and searching tasks.
