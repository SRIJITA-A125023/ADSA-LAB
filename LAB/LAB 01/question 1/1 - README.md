# 📖 Overview
This C program approximates and sorts the asymptotic growth rates of twelve mathematical functions for a large value of \( n \) (\( n = 102573 \)). It computes and compares their values, then prints their names and results in ascending order of evaluated output, effectively demonstrating comparative growth for algorithmic analysis.

# ⚙️ Usage
- Compile using: `gcc -lm -o growth growth.c`
- Run the program: `./growth`
- The program evaluates each function at \( n = 102573 \), sorts them by their output value, and prints the results in increasing order of growth.

No user input is required. The output is printed directly to the terminal.

# ⏳ Time Complexity
- Computing each function: O(1) per function.
- Sorting 12 elements: O(12 log 12) (negligible for this small fixed set).
- Overall complexity: O(1) since the number of functions is constant.

# 💾 Space Complexity
- Uses an array of 12 structures—fixed size.
- Minimal additional stack usage.
- Overall space complexity: O(1)

# 🧩 Examples
Sample output for ( n = 102573 ):
Functions in increasing order of growth (approximate for n=102573):

1/n => 9.749628e-06

log2 n => 16.657120e+00

12 sqrt(n) => 12102.886984e+00

50 sqrt(n) => 50428.694101e+00

n^0.51 => 3348.761742e+00

n log2 n => 1.708418e+06

n^2 - 324 => 1.052583e+10

100n^2 + 6n => 1.025831e+12

2n^3 => 2.163247e+15

n^(log2 n) => [Extremely large value]

2^32 * n => 4.407032e+14

3^n => [Overflow/huge value]

*(Values may vary slightly depending on math.h implementation and floating-point precision.)*

# 📦 Prerequisites
- Requires GCC (or compatible C compiler).
- Link math library: Use the `-lm` flag for math functions.

# ⚠️ Limitations
- Floating point functions like `pow(n, log2(n))` and `3^n` for large \( n \) may result in overflow or imprecise values due to floating-point limitations.
- Designed as a demonstration for comparative growth, not for exact computation for extremely large outputs.

---
This program is useful for illustrating differences in algorithmic complexity and growth for students and researchers in computer science.
