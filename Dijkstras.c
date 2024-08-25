#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to read the cost adjacency matrix from standard input and run Dijkstra's algorithm
void callDijkstras(int **graph, int nodes, int src) {
    int *dist = (int *)malloc((nodes + 1) * sizeof(int));  // Distance array
    int *visited = (int *)malloc((nodes + 1) * sizeof(int));  // Visited array

    // Initialize distances and visited array
    for (int i = 0; i <= nodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;  // Distance to the source is 0

    for (int c = 0; c < nodes; c++) {
        int u = -1;
        // Find the unvisited node with the smallest distance
        for (int i = 1; i <= nodes; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1) break;  // If no such node is found, break the loop

        visited[u] = 1;  // Mark the node as visited

        // Update distances of adjacent nodes
        for (int v = 1; v <= nodes; v++) {
            if (graph[u][v] != INT_MAX && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Output the distances from the source node
    printf("Vertex \t Distance from Source node\n");
    for (int i = 1; i <= nodes; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }

    // Free allocated memory
    free(dist);
    free(visited);
}

int main() {
    int nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    // Initialize adjacency matrix
    int **adjMatrix = (int **)malloc((nodes + 1) * sizeof(int *));
    for (int i = 0; i <= nodes; i++) {
        adjMatrix[i] = (int *)malloc((nodes + 1) * sizeof(int));
        for (int j = 0; j <= nodes; j++) {
            adjMatrix[i][j] = INT_MAX;  // Set initial distance to infinity
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            int weight;
            scanf("%d", &weight);
            if (weight != 0) {
                adjMatrix[i][j] = weight;
            }
        }
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    callDijkstras(adjMatrix, nodes, src);

    // Free allocated memory for the adjacency matrix
    for (int i = 0; i <= nodes; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
