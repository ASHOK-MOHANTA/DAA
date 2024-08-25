
//---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform topological sort using source removal method
void sourceRemoval(int A[MAX_SIZE][MAX_SIZE], int n) {
    int Indegree[MAX_SIZE] = {0}; // Array to store in-degrees of vertices
    int stack[MAX_SIZE], top = -1; // Stack to store vertices with in-degree 0

    // Compute in-degrees of all vertices
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            Indegree[j] += A[i][j];
        }
    }

    // Push all vertices with in-degree 0 onto the stack
    for (int i = 0; i < n; ++i) {
        if (Indegree[i] == 0) {
            stack[++top] = i;
        }
    }

    printf("Topological sequence: ");
    while (top != -1) {
        int v = stack[top--]; // Pop vertex from stack
        printf("%d ", v + 1); // Print vertex (1-indexed for readability)

        // Decrease in-degrees of adjacent vertices and push if in-degree becomes 0
        for (int i = 0; i < n; ++i) {
            if (A[v][i] == 1) {
                Indegree[i]--;
                if (Indegree[i] == 0) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &n);
    
    int A[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    sourceRemoval(A, n);
    return 0;
}
