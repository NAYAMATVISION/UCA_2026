#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to evaluate the postfix expression
int evaluatePostfix(char exp[]) {
    int stack[50]; // Constraint: Length of expression < 50
    int top = -1;

    
    char *token = strtok(exp, " ");
    
    while (token != NULL) {
        
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            
            int operand2 = stack[top--]; 
            int operand1 = stack[top--]; 
            
            
            if (strcmp(token, "+") == 0) stack[++top] = operand1 + operand2;
            else if (strcmp(token, "-") == 0) stack[++top] = operand1 - operand2;
            else if (strcmp(token, "*") == 0) stack[++top] = operand1 * operand2;
            else if (strcmp(token, "/") == 0) stack[++top] = operand1 / operand2;
        } 
        // If the token is a number
        else {
            stack[++top] = atoi(token); 
        }
        
        token = strtok(NULL, " "); 
    }

    return stack[top]; 
}

int main() {
    
    char expression[] = "2 3 1 * + 9 -"; 
    
    int result = evaluatePostfix(expression);
    printf("%d\n", result);

    return 0;
}
