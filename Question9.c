#include <stdio.h>
#include <stdlib.h>

const MAX_SIZE=5;

int arr[5];
int front = -1;
int rear = -1;

struct Node {
    int data;
    struct Node* next;
};

struct Node* frontLinkedList = NULL;
struct Node* rearLinkedList = NULL;

int isQueueEmpty() {
    return front == -1;
}

int isQueueFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isLinkedListEmpty() {
    return frontLinkedList == NULL;
}

int isLinkedListFull() {
    return (isQueueFull());
}

void enqueueArray(int item) {
    if (isQueueFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = item;
    printf("Enqueued %d into Queue\n", item);
}

int dequeueArray() {
    if (isQueueEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = arr[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    return item;
}

void enqueueLinkedList(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isLinkedListEmpty()) {
        frontLinkedList = rearLinkedList = newNode;
        rearLinkedList->next = frontLinkedList;
        printf("Enqueued %d into Linked List Queue\n", item);
    } else {
        rearLinkedList->next = newNode;
        rearLinkedList = newNode;
        rearLinkedList->next = frontLinkedList;
        printf("Enqueued %d into Linked List Queue\n", item);
    }
}

int dequeueLinkedList() {
    if (isLinkedListEmpty()) {
        printf("Linked List Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = frontLinkedList->data;
    if (frontLinkedList == rearLinkedList) {
        free(frontLinkedList);
        frontLinkedList = rearLinkedList = NULL;
    } else {
        struct Node* temp = frontLinkedList;
        frontLinkedList = frontLinkedList->next;
        rearLinkedList->next = frontLinkedList;
        free(temp);
    }
    return item;
}

void displayArray() {
    if (isQueueEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

void displayLinkedList() {
    if (isLinkedListEmpty()) {
        printf("Linked List Queue is empty.\n");
        return;
    }

    struct Node* current = frontLinkedList;
    printf("Linked List Queue: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != frontLinkedList);
    printf("\n");
}

int main() {
    int choice, item,flag=1;
    int queueTypeChoice;

    do {
        printf("Choose the type of circular queue:\n");
        printf("1. Array-based Circular Queue\n");
        printf("2. Linked List-based Circular Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &queueTypeChoice);

        switch (queueTypeChoice) {
        case 1:
            while (flag) {
                printf("Array-based Circular Queue Operations:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Is Queue Empty\n");
                printf("4. Is Queue Full\n");
                printf("5. Display Queue\n");
                printf("6. Back to Queue Type Selection\n");
                printf("7. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    printf("Enter item to enqueue: ");
                    scanf("%d", &item);
                    enqueueArray(item);
                    break;
                case 2:
                    printf("Dequeued: %d\n", dequeueArray());
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
                    displayArray();
                    break;
                case 6:
                	flag = 0;
                    break; // Back to Queue Type Selection
                case 7:
                    printf("Exiting program.\n");
                    exit(0);
                default:
                    printf("Invalid choice. Try again.\n");
                }
            }
            break;

        case 2:
            while (flag) {
                printf("Linked List-based Circular Queue Operations:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Is Queue Empty\n");
                printf("4. Is Queue Full\n");
                printf("5. Display Queue\n");
                printf("6. Back to Queue Type Selection\n");
                printf("7. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    printf("Enter item to enqueue: ");
                    scanf("%d", &item);
                    enqueueLinkedList(item);
                    break;
                case 2:
                    printf("Dequeued: %d\n", dequeueLinkedList());
                    break;
                case 3:
                    if (isLinkedListEmpty())
                        printf("Queue is empty.\n");
                    else
                        printf("Queue is not empty.\n");
                    break;
                case 4:
                    if (isLinkedListFull())
                        printf("Queue is full.\n");
                    else
                        printf("Queue is not full.\n");
                    break;
                case 5:
                    displayLinkedList();
                    break;
                case 6:
                	flag = 0;
                    break; // Back to Queue Type Selection
                case 7:
                    printf("Exiting program.\n");
                    exit(0);
                default:
                    printf("Invalid choice. Try again.\n");
                }
            }
            break;

        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (queueTypeChoice != 3);

    return 0;
}

