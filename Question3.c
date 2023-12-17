#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Creation of a new node for doubly linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display a doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void displayList_cdll(struct Node* head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    do
	{
        printf("%d -> ", current->data);
        current = current->next;
    }
	while (current != head);
    printf("\n");
}

// Function to insert a new node at the beginning of a doubly linked list
void insert_begin_dll(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        (head)->prev = newNode;
    }
    head = newNode;
}

// Function to insert a new node at the end of a doubly linked list
void insert_end_dll(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to insert a new node at a specified position in a doubly linked list
void insert_loc_dll(struct Node* head, int data, int loc) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    while (current != NULL && current->data != loc) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found.\n");
        return;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to delete the first node in a doubly linked list
void delete_begin_dll(struct Node* head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    head = current->next;
    if (head != NULL) {
        (head)->prev = NULL;
    }
    free(current);
}

// Function to delete the last node in a doubly linked list
void delete_end_dll(struct Node* head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(current);
}

// Function to delete a node with a specified value in a doubly linked list
void delete_loc_dll(struct Node* head, int loc) {
    struct Node* current = head;
    while (current != NULL && current->data != loc) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found.\n");
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

// Circular doubly linked list
// Function to insert at the beginning of a circular doubly linked list
void insert_begin_cdll(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        newNode->prev = (head)->prev;
        (head)->prev->next = newNode;
        (head)->prev = newNode;
        head = newNode;
    }
}

// Function to insert at the end of a circular doubly linked list
void insert_end_cdll(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        newNode->prev = (head)->prev;
        (head)->prev->next = newNode;
        (head)->prev = newNode;
    }
}

// Function to insert at a specified position in a circular doubly linked list
void insert_loc_cdll(struct Node* head, int data, int loc) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current->data != loc) {
        current = current->next;
        if (current == head) {
            printf("Element not found.\n");
            return;
        }
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// Function to delete the first node in a circular doubly linked list
void delete_begin_cdll(struct Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    head = current->next;
    free(current);
}

// Function to delete the last node in a circular doubly linked list
void delete_end_cdll(struct Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if (current->next == current) {
        head = NULL;
    } else {
        head = current->next;
    }
    free(current);
}

// Function to delete a node with a specified value in a circular doubly linked list
void delete_loc_cdll(struct Node* head, int loc) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current->data != loc) {
        current = current->next;
        if (current == head) {
            printf("Element not found.\n");
            return;
        }
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if (current == head) {
        head = current->next;
    }
    free(current);
}

int main() {
    struct Node* head = NULL;
    int choice1, choice2, data, position;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Doubly Linked List\n");
        printf("2. Circular Doubly Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
                head = NULL;
                while (1) {
                    printf("\nOperations on Doubly Linked List:\n");
                    printf("1. Insert\n");
                    printf("2. Delete\n");
                    printf("3. Back to Main Menu\n");
                    printf("4. Display Doubly Linklist\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            printf("1. Insert at beginning\n");
                            printf("2. Insert at end\n");
                            printf("3. Insert at specified location\n");
                            printf("4. Back to Previous Menu\n");
                            printf("5. Display the doubly linklist\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);

                            switch (position) {
                                case 1:
                                    insert_begin_dll(head, data);
                                    printf("List after insertion\n");
                                    displayList(head);
                                    break;
                                case 2:
                                    insert_end_dll(head, data);
                                    printf("List after insertion\n");
                                    displayList(head);
                                    break;
                                case 3:
                                    printf("Enter data to insert after: ");
                                    scanf("%d", &position);
                                    insert_loc_dll(head, data, position);
                                    printf("List after insertion\n");
                                    displayList(head);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                    printf("Doubly Linked List: ");
                                    displayList(head);
                                    break;
                                default:
                                    printf("Invalid choice\n");
                            }
                            break;
                        case 2:
                            printf("2. Delete Menu (Doubly Linked List)\n");
                            printf("1. Delete at beginning\n");
                            printf("2. Delete at end\n");
                            printf("3. Delete at specified location\n");
                            printf("4. Back to Previous Menu\n");
                            printf("5. Display the doubly linklist\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);

                            switch (position) {
                                case 1:
                                    delete_begin_dll(head);
                                    printf("List after deletion\n");
                                    displayList(head);
                                    break;
                                case 2:
                                    delete_end_dll(head);
                                    printf("List after deletion\n");
                                    displayList(head);
                                    break;
                                case 3:
                                    printf("Enter data to delete: ");
                                    scanf("%d", &position);
                                    delete_loc_dll(head, position);
                                    printf("List after deletion\n");
                                    displayList(head);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                    printf("Doubly Linked List: ");
                                    displayList(head);
                                    break;
                                default:
                                    printf("Invalid choice\n");
                                    break;
                            }
                            break;
                        case 3:
                            break;
                        case 4:
                            printf("Doubly Linked List: ");
                            displayList(head);
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                    if (choice2 == 3) {
                        break;
                    }
                }
                break;
            case 2:
                head = NULL;
                while (1) {
                    printf("\nOperations on Circular Doubly Linked List:\n");
                    printf("1. Insert\n");
                    printf("2. Delete\n");
                    printf("3. Back to Main Menu\n");
                    printf("4. Display Circular Doubly Linklist\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            printf("1. Insert at beginning\n");
                            printf("2. Insert at end\n");
                            printf("3. Insert at specified location\n");
                            printf("4. Back to Previous Menu\n");
                            printf("5. Display the circular doubly linklist\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);

                            switch (position) {
                                case 1:
                                    insert_begin_cdll(head, data);
                                    printf("List after insertion\n");
                                    displayList_cdll(head);
                                    break;
                                case 2:
                                    insert_end_cdll(head, data);
                                    printf("List after insertion\n");
                                    displayList_cdll(head);
                                    break;
                                case 3:
                                    printf("Enter data to insert after: ");
                                    scanf("%d", &position);
                                    insert_loc_cdll(head, data, position);
                                    printf("List after insertion\n");
                                    displayList_cdll(head);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                    printf("Circular Doubly Linked List: ");
                                    displayList_cdll(head);
                                    break;
                                default:
                                    printf("Invalid choice\n");
                            }
                            break;
                        case 2:
                            printf("2. Delete Menu (Circular Doubly Linked List)\n");
                            printf("1. Delete at beginning\n");
                            printf("2. Delete at end\n");
                            printf("3. Delete at specified location\n");
                            printf("4. Back to Previous Menu\n");
                            printf("5. Display the circular doubly linklist\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);

                            switch (position) {
                                case 1:
                                    delete_begin_cdll(head);
                                    printf("List after deletion\n");
                                    displayList_cdll(head);
                                    break;
                                case 2:
                                    delete_end_cdll(head);
                                    printf("List after deletion\n");
                                    displayList_cdll(head);
                                    break;
                                case 3:
                                    printf("Enter data to delete: ");
                                    scanf("%d", &position);
                                    delete_loc_cdll(head, position);
                                    printf("List after deletion\n");
                                    displayList_cdll(head);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                    printf("Circular Doubly Linked List: ");
                                    displayList_cdll(head);
                                    break;
                                default:
                                    printf("Invalid choice\n");
                                    break;
                            }
                            break;
                        case 3:
                            break;
                        case 4:
                            printf("Circular Doubly Linked List: ");
                            displayList_cdll(head);
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                    if (choice2 == 3) {
                        break;
                    }
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

