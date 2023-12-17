#include <stdio.h>

#define MAX 5

void DFS(int adj[][MAX], int visited[], int start) {
    int stack[MAX];
    int top = -1, i, k;
    for (k = 0; k < MAX; k++) {
        visited[k] = 0;
    }
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        start = stack[top--];
        printf("%c-", start + 'A');
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}

void BFS(int adj[][MAX], int visited[], int start) {
    int queue[MAX];
    int front = -1, rear = -1, i, k;

    for (k = 0; k < MAX; k++) {
        visited[k] = 0;
    }
    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front) {
        start = queue[front++];
        printf("%c-", start + 'A');
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    int option, size;

    printf("Enter the number of vertices (MAX <= 5): ");
    scanf("%d", &size);

    do {
        printf("Enter values in the graph\n");
		printf("Enter the adjacency matrix:\n");
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++)
				scanf("%d", &adj[i][j]);
            break;
        printf("\n ******MAIN MENU****** \n");
        printf("1. DFS Traversal\n");
        printf("2. BFS Traversal\n");
        printf("3. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("DFS Traversal: ");
                DFS(adj, visited, 0);
                printf("\n");
                break;

            case 2:
                printf("BFS Traversal: ");
                BFS(adj, visited, 0);
                printf("\n");
                break;
        }
    } while (option != 3);

    return 0;
}

