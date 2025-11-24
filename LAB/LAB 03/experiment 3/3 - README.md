# 📖 Overview
This C program converts an infix arithmetic expression containing single-digit operands to its postfix form using a stack-based algorithm, then evaluates the resulting postfix expression. Supported operators include `+`, `-`, `*`, `/`, and `^` (exponentiation), along with parentheses for precedence control.

# ⚙️ Usage
- Compile with: `gcc -o infix_postfix_eval infix_postfix_eval.c -lm`
- Run the program: `./infix_postfix_eval`
- Input a valid infix expression with single-digit numbers and operators.
- The program prints the postfix expression and its evaluated integer result.

Example:

    Enter an infix expression (use single-digit numbers): 
        (3+2)5^2-8/4
    
    Postfix expression: 
        32+5^284/-
    
    Evaluation result: 
        121

# ⏳ Time Complexity
- Both infix to postfix conversion and postfix evaluation run in O( n ) time, where n is the length of the expression.

# 💾 Space Complexity
- Uses O( n ) space for stacks and output arrays.

# 🧩 Examples
    Input:
        (1+2)*(3+4)
    
    Output:
        Postfix expression: 
          12+34+*
        Evaluation result: 
          21
        
    Input:
        5+6*7-8/4
    
    Output:
        Postfix expression: 
          567*+84/-
        Evaluation result: 
          44

---
This program provides a practical, step-by-step approach to expression parsing and evaluation using stacks, suitable for educational purposes in data structures and compiler design.


