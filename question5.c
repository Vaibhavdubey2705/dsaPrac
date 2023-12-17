#include <stdio.h>
#include<stdbool.h>

const MAX_SIZE = 5;

int stack[5];
int top = -1;

bool is_empty() {
    return top == -1;
}

bool is_full() {
    return top == MAX_SIZE - 1;
}

void push(int item) {
    if (is_full()) {
        printf("Stack Overflow: Cannot push item, the stack is full.\n");
    }
    else {
        stack[++top] = item;
        printf("Pushed %d onto the stack.\n", item);
    }
}

void pop() {
    if (is_empty()) {
        printf("Stack Underflow: Cannot pop from an empty stack.\n");
    }
    else {
        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

void display() {
    if (is_empty()) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack contents: ");
        int i;
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check for Stack Underflow\n");
        printf("4. Check for Stack Overflow\n");
        printf("5. Display Stack\n");
        printf("6. Quit\n");

        int choice,item;;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push onto the stack: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (is_empty())
                 printf("Stack is empty.\n");
                else
				{
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                if (is_full()) {
                    printf("Stack is full.\n");
                }
                else {
                    printf("Stack is not full.\n");
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}






