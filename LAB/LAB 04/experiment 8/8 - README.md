# 📖 Overview
This C program computes the Longest Common Subsequence (LCS) between two input strings using dynamic programming. It outputs the length of the LCS, one example LCS, and recursively prints all common subsequences (including duplicates). The program demonstrates LCS problem-solving and common subsequence extraction.

# ⚙️ Usage
- Compile with: `gcc -o lcs lcs.c`
- Run: `./lcs`
- Input two strings when prompted.
- The program prints the length of their LCS, one example LCS, and all common subsequences (which may include duplicates).

Example:

    Enter first string: ABCBDAB
    
    Enter second string: BDCAB
    
    Length of Longest Common Subsequence: 4
    
    Longest Common Subsequence: BCAB
    
    All Common Subsequences (may include duplicates):
        B
        C
        A
        B
        BC
        BA
        CAB
        ...

# ⏳ Time Complexity
- The dynamic programming LCS length calculation runs in O( mn ), where m,n are lengths of input strings.

# 💾 Space Complexity
- Uses O( mn ) space for the DP table and O( m+n ) for recursive subsequence storage.

# 🧩 Examples
    Input:
    
        X = AGGTAB
        Y = GXTXAYB
        
    Output:
    
        Length of Longest Common Subsequence: 4
        
        Longest Common Subsequence: GTAB
        
        All Common Subsequences (may include duplicates):
            G
            T
            A
            B
            GT
            GA
            GB
            ...

---
This program offers comprehensive insight into LCS problems, showing length calculation, single LCS recovery, and exploration of all common subsequences.
