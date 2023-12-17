#include <stdio.h>
#include <stdlib.h>

const MAX_SIZE = 5;

struct Node {
    int data;
    struct Node* next;
};

struct Node* stackTop = NULL;
struct Node* queueFront = NULL;
struct Node* queueRear = NULL;

// Function to push an item onto the stack
void push(int item) {
    if (isStackFull()) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = stackTop;
    stackTop = newNode;
    printf("Pushed %d onto the stack\n", item);
}

// Function to pop an item from the stack
int pop() {
    if (stackTop == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    int item = stackTop->data;
    struct Node* temp = stackTop;
    stackTop = stackTop->next;
    free(temp);
    return item;
}

// Function to check if the stack is empty
int isStackEmpty() {
    return stackTop == NULL;
}

// Function to check if the stack is full
int isStackFull() {
    return stackSize() == MAX_SIZE;
}

// Function to get the size of the stack
int stackSize() {
    int size = 0;
    struct Node* current = stackTop;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

// Function to display the stack
void displayStack() {
    if (isStackEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* current = stackTop;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to enqueue an item into the queue
void enqueue(int item) {
    if (isQueueFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    if (queueRear == NULL) {
        queueFront = queueRear = newNode;
    } else {
        queueRear->next = newNode;
        queueRear = newNode;
    }
    printf("Enqueued %d into the queue\n", item);
}

// Function to dequeue an item from the queue
int dequeue() {
    if (queueFront == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queueFront->data;
    struct Node* temp = queueFront;
    queueFront = queueFront->next;
    if (queueFront == NULL) {
        queueRear = NULL;
    }
    free(temp);
    return item;
}

// Function to check if the queue is empty
int isQueueEmpty() {
    return queueFront == NULL;
}

// Function to check if the queue is full
int isQueueFull() {
    return queueSize() == MAX_SIZE;
}

// Function to get the size of the queue
int queueSize() {
    int size = 0;
    struct Node* current = queueFront;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

// Function to display the queue
void displayQueue() {
    if (isQueueEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queueFront;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int dataStructureChoice;
    int choice, item;

    while (1) {
        printf("Choose a data structure:\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &dataStructureChoice);

        if (dataStructureChoice == 1) {
            while (1) {
                printf("Stack Operations:\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Is Stack Empty\n");
                printf("4. Is Stack Full\n");
                printf("5. Display Stack\n");
                printf("6. Back to Data Structure Selection\n");
                printf("7. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter item to push onto the stack: ");
                        scanf("%d", &item);
                        push(item);
                        break;
                    case 2:
                        printf("Popped from the stack: %d\n", pop());
                        break;
                    case 3:
                        if (isStackEmpty())
                            printf("Stack is empty.\n");
                        else
                            printf("Stack is not empty.\n");
                        break;
                    case 4:
                        if (isStackFull())
                            printf("Stack is full.\n");
                        else
                            printf("Stack is not full.\n");
                        break;
                    case 5:
                        displayStack();
                        break;
                    case 6:
                        break; // Go back to Data Structure Selection
                    case 7:
                        printf("Exiting program.\n");
                        exit(0);
                    default:
                        printf("Invalid choice. Try again.\n");
                }
            }
        } else if (dataStructureChoice == 2) {
            while (1) {
                printf("Queue Operations:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Is Queue Empty\n");
                printf("4. Is Queue Full\n");
                printf("5. Display Queue\n");
                printf("6. Back to Data Structure Selection\n");
                printf("7. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter item to enqueue into the queue: ");
                        scanf("%d", &item);
                        enqueue(item);
                        break;
                    case 2:
                        printf("Dequeued from the queue: %d\n", dequeue());
                        break;
                    case 3:
                        if (isQueueEmpty())
                            printf("Queue is empty.\n");
                        else
                            printf("Queue is not empty.\n");
                        break;
                    case 4:
                        if (isQueueFull())
                            printf("Queue is full.\n");
                        else
                            printf("Queue is not full.\n");
                        break;
                    case 5:
                        displayQueue();
                        break;
                    case 6:
                        break; // Go back to Data Structure Selection
                    case 7:
                        printf("Exiting program.\n");
                        exit(0);
                    default:
                        printf("Invalid choice. Try again.\n");
                }
            }
        } else if (dataStructureChoice == 3) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

