#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};
//Creation of a new node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//Function to display a list
void displayList(struct Node* head) {
	if (head == NULL)
	{
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
void displayList_csll(struct Node* head) {
	if (head == NULL)
	{
		printf("Circular Linked List is empty.\n");
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
//1. Function to insert a new node at begining
void insert_begin_sll(struct Node** head, int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}
//2. Function to insert at end
void insert_end_sll(struct Node** head,int data)
{
	struct Node* newNode = createNode(data);
	struct Node* current = *head;
	if(*head==NULL)
	{
		*head=newNode;
		return;
	}
	else
	{
		while(current->next!=NULL)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->next  = NULL;
	}
}
//3. Function to insert at specified postion in sll
void insert_loc_sll(struct Node** head,int data,int loc)
{
	struct Node* newNode = createNode(data);
	struct Node* current = *head;
	if(*head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	else
	{
		while(current !=NULL && current->data!=loc)
		{
			current = current->next;
		}
		if(current==NULL)
			{
				printf("Element not found \n");
				return;
			}
		struct Node* ptr = current->next;
		current->next  = newNode;
		newNode->next = ptr;
		
	}
}
//4. Deletion at begin for SLL
void delete_begin_sll(struct Node** head)
{
	if(*head==NULL)
	{
		printf("List is empty \n");
		return;
	}
	else
	{
		struct Node* current = *head;
		*head  = current->next;
		free(current);
	}
}
//5. Deletion at end for SLL
void delete_end_sll(struct Node** head)
{
	if(*head==NULL)
	{
		printf("List is empty \n");
		return;
	}
	else{
		struct Node* current = *head;
		struct Node* ptr = current->next;
		while(ptr->next!=NULL)
		{
			current = current->next;
			ptr = ptr->next;
		}
		current->next = NULL;
		free(ptr);
	}	
}
//6. Deletion at end for SLL
void delete_loc_sll(struct Node** head,int loc)
{
	if(*head==NULL)
	{
		printf("List is empty \n");
		return;
	}
//	else if(head->data==loc)
//	{
//		delete_begin_sll(head);
//		return;
//	}
	else
	{
		struct Node* current = *head;
		struct Node* ptr = current->next;
		while(ptr->data!=loc)
		{
			current = current->next;
			ptr = ptr->next;
			if(current->next==NULL)
			{
				printf("Element not found \n");
				return;
			}
			
		}
		current->next = ptr->next;
		free(ptr);	
	}
}
// Circular single LinkList
// 7. Function to insert at begin
void insert_begin_csll(struct Node** head,int data)
{
	struct Node* current = *head;
	struct Node* newNode = createNode(data);
	if(*head==NULL)
	{
		*head = newNode;
		newNode->next = newNode;;
		return;
	}
	else
	{
		newNode->next = *head;
		while(current->next!=*head)
		{
			current = current->next;
		}
		current->next = newNode;
		*head = newNode;
	}	
}
// 8. Function to insert at end of a circular link list
void insert_end_csll(struct Node** head,int data)
{
	struct Node* newNode = createNode(data);
	struct Node* current = *head;
	if(*head==NULL)
	{
		*head=newNode;
		newNode->next = newNode;
		return;
	}
	else
	{
		while(current->next!=*head)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->next  = *head;
	}
}
//9. Function to insert at specified postion in csll
void insert_loc_csll(struct Node** head,int data,int loc)
{
	struct Node* newNode = createNode(data);
	struct Node* current = *head;
	if(*head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	else
	{
		while(current->data!=loc)
		{
			current = current->next;
			if(current->next==NULL)
			{
				printf("Element not found \n");
			}
		}
		struct Node* ptr = current->next;
		current->next  = newNode;
		newNode->next = ptr;
		
	}
}
// 10. function to delete from begining in csll
void delete_begin_csll(struct Node** head)
{
	if(*head==NULL)
	{
		printf("List is empty \n");
		return;
	}
	else
	{
		struct Node* current = *head;
		while(current->next!=*head)
		{
			current=current->next;
		}
		struct Node* ptr = current->next;
		current->next = ptr->next;
		free(ptr);
		*head = current->next;
	}
}
// 11. function to delete from end in csll
void delete_end_csll(struct Node** head)
{
	if(*head==NULL)
	{
		printf("List is empty \n");
		return;
	}
	else
	{
		struct Node* current = *head;
		while(current->next->next!=*head)
		{
			current=current->next;
		}
		struct Node* ptr = current->next;
		current->next = ptr->next;
		free(ptr);
	}
}
// 12. Delete for a loc in csll
void delete_loc_csll(struct Node** head,int loc)
{
	if(*head==NULL)
	{
		printf("List is empty \n");
		return;
	}
	else
	{
		struct Node* current = *head;
		struct Node* ptr = current->next;
		while(ptr->data!=loc)
		{
			current = current->next;
			ptr = ptr->next;
			if(current->next==*head)
			{
				printf("Element not found \n");
				return;
			}
			
		}
		current->next = ptr->next;
		free(ptr);	
	}
}
int main()
{
	struct Node* head = NULL;
    int choice1, choice2, data, position;

    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Singly Linked List\n");
        printf("2. Circular Singly Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
				 head=NULL;
                while (1) {
                    printf("\nOperations on Singly Linked List:\n");
                    printf("1. Insert\n");
                    printf("2. Delete\n");
                    printf("3. Back to Main Menu\n");
                    printf("4. Display Linklist\n");
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
                            printf("5. Display the linklist\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);

                            switch (position) {
                                case 1:
                                    insert_begin_sll(&head, data);
                                    break;
                                case 2:
                                    insert_end_sll(&head, data);
                                    break;
                                case 3:
                                    printf("Enter data to insert after: ");
                                    scanf("%d", &position);
                                    insert_loc_sll(&head,data,position);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                	printf("Linked List: ");
                            		displayList(head);
                            		break;
                                default:
                                    printf("Invalid choice\n");
                            }
                            break;
                        case 2:
                            // Implement deletion menu for Singly Linked List
                            printf("2. Delete Menu (Singly Linked List)\n");
                            printf("1. Delete at beginning\n");
                            printf("2. Delete at end\n");
                            printf("3. Delete at specified location\n");
                            printf("4. Back to Previous Menu\n");
                            printf("5. Display the linklist");
                            printf("Enter your choice: \n");
                            scanf("%d", &position);
                            switch (position) {
                                case 1:
                                    delete_begin_sll(&head);
                                    break;
                                case 2:
                                    delete_end_sll(&head);
                                    break;
                                case 3:
                                    printf("Enter data to insert after: ");
                                    scanf("%d", &position);
                                    delete_loc_sll(&head,position);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                	printf("Linked List: ");
                            		displayList(head);
                            		break;
                                default:
                                    printf("Invalid choice\n");
                            }
                            break;
                        case 3:
                            // Go back to Main Menu
                            break;
                        case 4:
                        	printf("Linked List: ");
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
                    printf("\nOperations on Circular Singly Linked List:\n");
                    printf("1. Insert\n");
                    printf("2. Delete\n");
                    printf("3. Back to Main Menu\n");
                    printf("4. Display Linklist\n");
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
                            printf("5. Display the linklist \n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);

                            switch (position) {
                                case 1:
                                    insert_begin_csll(&head, data);
                                    break;
                                case 2:
                                    insert_end_csll(&head, data);
                                    break;
                                case 3:
                                    printf("Enter data to insert after: ");
                                    scanf("%d", &position);
                                    insert_loc_csll(&head,data,position);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                	printf("Linked List: \n");
                            		displayList_csll(head);
                                default:
                                    printf("Invalid choice\n");
                            }
                            break;
                        case 2:
                            // Implement deletion menu for Circular Singly Linked List
                            printf("2. Delete Menu (Singly Linked List)\n");
                            printf("1. Delete at beginning\n");
                            printf("2. Delete at end\n");
                            printf("3. Delete at specified location\n");
                            printf("4. Back to Previous Menu\n");
                            printf("5. Display the linklist\n");
                            printf("Enter your choice: ");
                            scanf("%d", &position);
                            switch (position) {
                                case 1:
                                    delete_begin_csll(&head);
                                    break;
                                case 2:
                                    delete_end_csll(&head);
                                    break;
                                case 3:
                                    printf("Enter data to insert after: ");
                                    scanf("%d", &position);
                                    delete_loc_csll(&head,position);
                                    break;
                                case 4:
                                    break;
                                case 5:
                                	printf("Linked List: ");
                            		displayList_csll(head);
                            		break;
                                default:
                                    printf("Invalid choice\n");
                                break;
                            }
                        case 3:
                            // Go back to Main Menu
                            break;
                        case 4:
                        	printf("Linked List: ");
                            displayList_csll(head);
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
                // Exit the program
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
