#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_STACK_SIZE 100

// Define the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Custom stack implementation as an array
double stack[MAX_STACK_SIZE];
int top = -1;

void push(double item) {
    if (top < MAX_STACK_SIZE - 1)
        stack[++top] = item;
}

double pop() {
    if (top >= 0)
        return stack[top--];
    return 0.0;  // Return 0.0 for an empty stack
}
char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';  // Return null character for an empty stack
}
bool isEmpty() {
    return top == -1;
}
void infixToPostfix(const char *infix, char *postfix) {
    int i, j;
    i = j = 0;
    char token;
    char c;

    //push('(');  // Push an opening parenthesis onto the stack

    while ((token = infix[i++]) != '\0') {
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while ((c = pop()) != '(') {
                postfix[j++] = c;
            }
        } else {
            while (precedence(token) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}
// Function to evaluate a postfix expression
double evaluatePostfix(const char *postfix) {
    int i = 0;
    char token;
    double operand1, operand2;

    while ((token = postfix[i++]) != '\0') {
        if (isdigit(token)) {
            push(token - '0'); // Convert character digit to integer and push onto stack
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (token) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '^':
                	push(pow(operand1,operand2));
                	break;
            }
        }
    }

    return pop();
}

int main() {
    while (1) {
        printf("Menu:\n");
        printf("1. Evaluate the Expression\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char infixExpression[MAX_STACK_SIZE];
            char postfixExpression[MAX_STACK_SIZE];
            printf("Enter an infix expression: ");
            scanf(" %[^\n]", infixExpression);
            infixToPostfix(infixExpression, postfixExpression);
            printf("Postfix expression: %s\n", postfixExpression);
            double res = evaluatePostfix(postfixExpression);
            printf("Result of above expression is %.2lf\n", res);
            break;
        }
		else if (choice == 2) {
            break;
        }
		else{
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

