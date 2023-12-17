#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

int MAX_SIZE = 5;
int queue[5];
int front = -1, rear = -1;

bool isFull() {
    return (rear == MAX_SIZE - 1 && front == 0) || (rear + 1 == front);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = item;
        if (front == -1) {
            front = rear; // First element in the queue
        }
        printf("%d enqueued to the queue.\n", item);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    } else {
        int item = queue[front];
        if (front == rear) {
            front = rear = -1; // Last element in the queue
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Is Queue Full\n");
        printf("5. Is Queue Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
            	if(isFull())
            	{
            		printf("Queue is Full\n");
				}
				else 
				{
					printf("Queue is not full\n");
				}
				break;
			case 5:
            	if(isEmpty())
            	{
            		printf("Queue is Empty\n");
				}
				else 
				{
					printf("Queue is not empty\n");
				}
				break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

