# 📖 Overview
This C program implements Huffman coding for lossless text compression. It reads an input text, calculates frequencies of each character, builds a Huffman tree based on frequencies, generates prefix codes for each character, and outputs the encoded binary message along with the Huffman codes for each character.

# ⚙️ Usage
- Compile with: `gcc -o huffman huffman.c`
- Run: `./huffman`
- Input a text string (up to 1000 characters).
- The program outputs the Huffman codes for each character present and prints the encoded binary string representation of the entire text.

Example:

    Enter text (max 1000 chars): hello world
    
    Original Message:
      hello world
    
    Huffman Codes for each character:
        'd': 001
        'e': 010
        'h': 000
        'l': 11
        'o': 10
        ' ': 011
        'r': 100
        'w': 101
        
    Final Encoded Message:
      000010111111010011100101001

# ⏳ Time Complexity
- Frequency counting is O( n ) where n is text length.
- Building Huffman tree takes O( m^2 ) where m is number of unique characters.
- Generating codes is O( m ).

# 💾 Space Complexity
- Uses O( m ) for frequency arrays and node arrays.
- Encoded message size depends on input length and compression achieved.

# 🧩 Examples
      Input:
          data compression
      
      Output:
          Original Message:
          data compression
          
      Huffman Codes for each character:
          ' ': 101
          'a': 001
          'c': 011
          'd': 000
          'e': 010
          'i': 1000
          'm': 1001
          'n': 1110
          'o': 1111
          'p': 1100
          'r': 1101
          's': 1010
      
      Final Encoded Message:
          0000010100111011001100101000100111001100111110001111011001101010

---
This program illustrates efficient text encoding through Huffman coding, a foundational technique in data compression systems.



