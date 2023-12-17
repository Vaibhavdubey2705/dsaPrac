#include <stdio.h>
#include <stdlib.h>

// Function to input a matrix
void inputMatrix(int row, int col, int arr[row][col]) {
    int i,j;
    printf("Enter matrix elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

// Function to check if a matrix is sparse and return the number of non-zero elements
int checkSparse(int row, int col, int arr[row][col]) {
    int count = 0,i,j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] != 0)
                count++;
        }
    }
    //50% 
    if (count > (row * col) / 2)
        return 0;
    else
        return count;
}

// Function to convert a matrix to a compact form
void matrixConversion(int compactMatrix[][3], int row, int col,int arr[][col]) {
    int k = 0,i,j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = arr[i][j];
                k++;
            }
        }
    }
}

int main() {
    int row, col,i;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);
    // Input matrix from the user
    int arr[row][col];
    inputMatrix(row, col, arr);
    // Check sparsity and get the count of non-zero elements
    int count = checkSparse(row, col, arr);
    printf("Number of non-zero elements: %d\n", count);

    if (count == 0) {
        printf("The matrix is not sparse.\n");
    } else {
        // Create a compact matrix
        int compactMatrix[count][3];
        matrixConversion(compactMatrix, row, col,arr);

        // Display compact matrix
        printf("Compact Matrix:\n");
        printf("%d %d %d\n", row, col,count);
        for (i = 0; i < count; i++) {
            printf("%d %d %d\n", compactMatrix[i][0], compactMatrix[i][1], compactMatrix[i][2]);
        }
    }

    return 0;
}

