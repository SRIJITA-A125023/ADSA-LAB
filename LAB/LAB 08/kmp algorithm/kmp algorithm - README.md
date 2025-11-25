# 📖 Overview
This C program implements the Knuth-Morris-Pratt (KMP) string matching algorithm. It efficiently searches for all occurrences of a given pattern within a text by preprocessing the pattern to build the Longest Prefix Suffix (LPS) array, enabling the algorithm to avoid unnecessary comparisons.

# ⚙️ Usage
- Compile the program using a C compiler:
  
      gcc -o kmp_search kmp_search.c


- Run the program:
    
      ./kmp_search

- Input the text when prompted.
- Input the pattern to search for within the text.
- The program outputs all starting indices where the pattern is found, or indicates if the pattern is not present.

- Example usage:
 
        Enter the text: ABABDABACDABABCABAB
  
        Enter the pattern: ABABCABAB
        
        --- KMP String Search Results ---
            Pattern found at index 10
        
        
# ⏳ Time Complexity
- The overall time complexity is O( n + m ), where n is the length of the text and m is the length of the pattern.
- The LPS array is computed in O( m ) time, and the search process navigates the text in O( n ) time.

# 💾 Space Complexity
- Uses O( m ) space to store the LPS array.
- Additional O( 1 ) space for variables and counters.

# 🧩 Examples
    Input:

        Text: ABC ABCDAB ABCDABCDABDE
        
        Pattern: ABCDABD
        
    
    Output:
    
        Pattern found at index 15
    
    
    Input:
    
        Text: HELLO WORLD
        
        Pattern: TEST
    
    Output:
        Pattern not found in text.

    

---
This program is useful for understanding and demonstrating efficient pattern searching techniques that are foundational in algorithms and text processing.
