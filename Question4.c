#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Creation of a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display a list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to reverse a singly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev; // The new head of the reversed list
}

// Function to insert a new node at the beginning of the list
void insert_begin_sll(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insert_end_sll(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

// Function to insert a new node at a specified position in the list
void insert_loc_sll(struct Node** head, int data, int loc) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (current != NULL && current->data != loc) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Element not found\n");
        return;
    }
    
    struct Node* ptr = current->next;
    current->next = newNode;
    newNode->next = ptr;
}

// Function to delete a node from the beginning of the list
void delete_begin_sll(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* current = *head;
    *head = current->next;
    free(current);
}

// Function to delete a node from the end of the list
void delete_end_sll(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* current = *head;
    struct Node* ptr = current->next;
    
    while (ptr->next != NULL) {
        current = current->next;
        ptr = ptr->next;
    }
    
    current->next = NULL;
    free(ptr);
}

// Function to delete a node with a specific data value from the list
void delete_loc_sll(struct Node** head, int loc) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* current = *head;
    struct Node* ptr = current->next;
    
    while (ptr->data != loc) {
        current = current->next;
        ptr = ptr->next;
        
        if (current->next == NULL) {
            printf("Element not found\n");
            return;
        }
    }
    
    current->next = ptr->next;
    free(ptr);
}

int main() {
    struct Node* head = NULL;
    int choice1, choice2, data, position;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Reverse\n");
        printf("4. Count\n");
        printf("5. Display Linklist\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
                while (1) {
                    printf("\nInsert Menu:\n");
                    printf("1. Insert at beginning\n");
                    printf("2. Insert at end\n");
                    printf("3. Insert at specified location\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1:
                            printf("Enter data to insert at the beginning: ");
                            scanf("%d", &data);
                            insert_begin_sll(&head, data);
                            displayList(head);
                            break;
                        case 2:
                            printf("Enter data to insert at the end: ");
                            scanf("%d", &data);
                            insert_end_sll(&head, data);
                            displayList(head);
                            break;
                        case 3:
                            printf("Enter data to insert: ");
                            scanf("%d", &data);
                            printf("Enter data to insert after: ");
                            scanf("%d", &position);
                            insert_loc_sll(&head, data, position);
                            displayList(head);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                    if (choice2 == 4) {
                        break;
                    }
                }
                break;
            case 2:
                while (1) {
                    printf("\nDelete Menu:\n");
                    printf("1. Delete at beginning\n");
                    printf("2. Delete at end\n");
                    printf("3. Delete at specified location\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice2);

                    switch (choice2) {
                        case 1:
                            delete_begin_sll(&head);
                            displayList(head);
                            break;
                        case 2:
                            delete_end_sll(&head);
                            displayList(head);
                            break;
                        case 3:
                            printf("Enter data to delete: ");
                            scanf("%d", &data);
                            delete_loc_sll(&head, data);
                            displayList(head);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice\n");
                    }
                    if (choice2 == 4) {
                        break;
                    }
                }
                break;
            case 3:
                head = reverseList(head);
                displayList(head);
                printf("Linked List reversed\n");
                break;
            case 4:
                printf("Number of nodes in the list: %d\n", countNodes(head));
                break;
            case 5:
                printf("Linked List: ");
                displayList(head);
                break;
            case 6:
                // Exit the program
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

