#include <stdio.h>
#include <stdlib.h>

void traverse(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert_at_begin(int arr[], int *n, int size, int data) {
    if (*n >= size) {
        printf("No empty space \n");
        return;
    }
    if (*n == 0) {
        arr[0] = data;
    } else {
        int i = *n;
        while (i >= 1) {
            arr[i] = arr[i - 1];
            i--;
        }
        arr[0] = data;
    }
    (*n)++;
}

void insert_at_end(int arr[], int *n, int size, int data) {
    if (*n >= size) {
        printf("No empty space \n");
        return;
    }
    arr[*n] = data;
    (*n)++;
}

void insert_at_loca(int arr[], int *n, int size, int data, int loc) {
    if (*n >= size) {
        printf("No empty space\n");
        return;
    }
    if (loc < 0 || loc > *n) {
        printf("Invalid location\n");
        return;
    }
    if (loc == *n) {
        arr[*n] = data;
    } else {
        int i;
        for (i = *n; i > loc; i--) {
            arr[i] = arr[i - 1];
        }
        arr[loc] = data;
    }
    (*n)++;
}

void delete_at_end(int arr[], int *n) {
    if (*n == 0) {
        printf("Array is empty\n");
        return;
    }
    arr[(*n) - 1] = 0;
    (*n)--;
}

void delete_at_begin(int arr[], int *n) {
    if (*n == 0) {
        printf("Array is empty\n");
        return;
    }
    int i;
    for (i = 0; i < (*n) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void delete_at_loc(int arr[], int *n, int loc) {
    if (loc >= *n) {
        printf("Location is out of size of array \n");
        return;
    }
    if (*n == 0) {
        printf("Array is empty \n");
        return;
    }
    int i;
    for (i = loc; i < (*n) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[(*n) - 1] = 0;
    (*n)--;
}

int linear_search(int arr[], int n, int data) {
    int loc = -1, i;
    for (i = 0; i < n; i++) {
        if (arr[i] == data) {
            loc = i;
            break;
        }
    }
    return loc;
}

void selection_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void insertMenu(int arr[], int *n, int size) {
    while (1) {
        int choice;
        printf("\nInsert Menu:\n");
        printf("1. Insert element at the beginning\n");
        printf("2. Insert element at the end\n");
        printf("3. Insert element at a specified location\n");
        printf("4. Back to Main Menu\n");
        printf("5. Display the array\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int element;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert_at_begin(arr, n, size, element);
                break;
            }
            case 2: {
                int element;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert_at_end(arr, n, size, element);
                break;
            }
            case 3: {
                int element, position;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insert_at_loca(arr, n, size, element, position);
                break;
            }
            case 4:
                return; // Return to the main menu
            case 5:
                traverse(arr, *n);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void deleteMenu(int arr[], int *n) {
    while (1) {
        int choice;
        printf("\nDelete Menu:\n");
        printf("1. Delete element at the beginning\n");
        printf("2. Delete element at the end\n");
        printf("3. Delete element at a specified location\n");
        printf("4. Back to Main Menu\n");
        printf("5. Display the array\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                delete_at_begin(arr, n);
                break;
            }
            case 2: {
                delete_at_end(arr, n);
                break;
            }
            case 3: {
                int position;
                printf("Enter the position to delete at: ");
                scanf("%d", &position);
                delete_at_loc(arr, n, position);
                break;
            }
            case 4:
                return; // Return to the main menu
            case 5:
                traverse(arr, *n);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    int size, n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the number of elements you want to enter in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = n; i < size; i++) {
        arr[i] = -1;
    }

    while (1) {
        int choice;
        printf("\nMain Menu:\n");
        printf("1. Insert Menu\n");
        printf("2. Delete Menu\n");
        printf("3. Display array\n");
        printf("4. Linear search\n");
        printf("5. Bubble sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertMenu(arr, &n, size);
                break;
            case 2:
                deleteMenu(arr, &n);
                break;
            case 3:
                traverse(arr, n);
                break;
            case 4: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                int loc = linear_search(arr, n, element);
                if (loc == -1) {
                    printf("Element not found.\n");
                } else {
                    printf("Element found at position %d\n", loc);
                }
                break;
            }
            case 5:
                selection_sort(arr, n);
                printf("Array sorted successfully.\n");
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

