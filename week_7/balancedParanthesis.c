#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if characters form a matching pair
bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return true;
    if (character1 == '{' && character2 == '}') return true;
    if (character1 == '[' && character2 == ']') return true;
    return false;
}

// Function to check if the expression is balanced
bool isBalanced(char exp[]) {
    int length = strlen(exp);
    char stack[35]; 
    int top = -1;

    for (int i = 0; i < length; i++) {
        
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        }
        
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            
            if (top == -1) {
                return false;
            }
            
            else if (!isMatchingPair(stack[top--], exp[i])) {
                return false;
            }
        }
    }

    
    return (top == -1);
}

int main() {
    char exp1[] = "[()]{}{()()}";
    char exp2[] = "[()";

    printf("Expression: %s -> %s\n", exp1, isBalanced(exp1) ? "true" : "false");
    printf("Expression: %s -> %s\n", exp2, isBalanced(exp2) ? "true" : "false");

    return 0;
}
