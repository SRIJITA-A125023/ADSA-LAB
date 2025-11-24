# 📖 Overview
This C program identifies a defective lighter coin from a collection of coins using a divide-and-conquer approach. It simulates a balance scale by comparing sums of coin weights from two halves, recursively narrowing down the search to find the lighter coin efficiently.

# ⚙️ Usage
- Compile with: `gcc -o find_lighter_coin find_lighter_coin.c`
- Run the executable: `./find_lighter_coin`
- Input the number of coins.
- Provide the weights of the coins (assuming all except possibly one have the same normal weight).
- The program outputs the index and weight of the lighter coin if found, or states that all coins are perfect.

Example:

Enter number of coins: 5

Enter weights of 5 coins: 10 10 9 10 10

Defective lighter coin found at index 2 (weight = 9)

# ⏳ Time Complexity
- The algorithm divides the problem range roughly in half at each step.
- Time complexity is O(log n) where n is the number of coins.

# 💾 Space Complexity
- Uses O(log n) space due to recursion stack depth.
- No additional significant space apart from input storage.

# 🧩 Examples
Input:
Enter number of coins: 6
Enter weights: 5 5 5 5 4 5

Output:
Defective lighter coin found at index 4 (weight = 4)

Input:
Enter number of coins: 4
Enter weights: 7 7 7 7

Output:
All coins are perfect. No lighter coin found.



---
This method efficiently finds a single lighter defective coin using minimal weigh comparisons.
