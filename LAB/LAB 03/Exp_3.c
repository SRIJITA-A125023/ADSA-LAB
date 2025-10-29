#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// Stack for characters (operators)
typedef struct {
    char items[MAX];
    int top;
} CharStack;

// Stack for integers (operands)
typedef struct {
    int items[MAX];
    int top;
} IntStack;

void pushChar(CharStack *s, char value) {
    s->items[++(s->top)] = value;
}

char popChar(CharStack *s) {
    return s->items[(s->top)--];
}

char peekChar(CharStack *s) {
    return s->items[s->top];
}

int isEmptyChar(CharStack *s) {
    return s->top == -1;
}

void pushInt(IntStack *s, int value) {
    s->items[++(s->top)] = value;
}

int popInt(IntStack *s) {
    return s->items[(s->top)--];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    CharStack s;
    s.top = -1;
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isspace(ch)) continue;

        if (isalnum(ch)) {         // Operand
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(')
                postfix[k++] = popChar(&s);
            popChar(&s); // Remove '('
        }
        else if (isOperator(ch)) {
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) >= precedence(ch))
                postfix[k++] = popChar(&s);
            pushChar(&s, ch);
        }
    }
    while (!isEmptyChar(&s))
        postfix[k++] = popChar(&s);

    postfix[k] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    IntStack s;
    s.top = -1;
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            pushInt(&s, ch - '0');
        }
        else if (isOperator(ch)) {
            int val2 = popInt(&s);
            int val1 = popInt(&s);
            switch (ch) {
                case '+': pushInt(&s, val1 + val2); break;
                case '-': pushInt(&s, val1 - val2); break;
                case '*': pushInt(&s, val1 * val2); break;
                case '/': pushInt(&s, val1 / val2); break;
                case '^': pushInt(&s, (int)pow(val1, val2)); break;
            }
        }
    }
    return popInt(&s);
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (use single-digit numbers): ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // remove newline

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}

