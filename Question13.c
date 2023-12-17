#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Binary Search Tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define a structure for a stack node
struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(struct TreeNode* treeNode) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = treeNode;
    stackNode->next = NULL;
    return stackNode;
}

// Function to push a node onto the stack
void push(struct StackNode** top, struct TreeNode* treeNode) {
    struct StackNode* stackNode = createStackNode(treeNode);
    stackNode->next = *top;
    *top = stackNode;
}

// Function to pop a node from the stack
struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }

    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct TreeNode* popped = temp->node;
    free(temp);
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Function to perform inorder traversal of the BST using a stack
void inorderTraversal(struct TreeNode* root) {
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to perform preorder traversal of the BST using a stack
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(&stack, current->right);
        }

        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

// Function to perform postorder traversal of the BST using two stacks
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL) {
            push(&stack1, current->left);
        }

        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    while (!isEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

// Function to insert a node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the node with the minimum value in a BST
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to display the menu
void displayMenu() {
    printf("\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Inorder Traversal\n");
    printf("4. Preorder Traversal\n");
    printf("5. Postorder Traversal\n");
    printf("6. Search\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Element found in the BST.\n");
                } else {
                    printf("Element not found in the BST.\n");
                }
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

