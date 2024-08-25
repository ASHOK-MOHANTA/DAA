#include <stdio.h>
#include <limits.h> // for INT_MAX

#define MAX_VERTICES 100 // Adjust this value based on the maximum number of vertices you expect

// Function to construct and print MST using Prim's algorithm
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V, int startNode) {
    int parent[MAX_VERTICES]; // Array to store constructed MST
    int key[MAX_VERTICES]; // Key values used to pick minimum weight edge in cut
    int inMST[MAX_VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and inMST[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0; // false
    }

    // Initialize the key of the starting vertex to 0 so that it is picked first
    key[startNode] = 0;
    parent[startNode] = -1; // Start node is always the root of the MST

    int totalWeight = 0;

    // The MST will have V vertices
    for (int count = 0; count < V; count++) {
        // Find the minimum key vertex from the set of vertices not yet included in MST
        int min = INT_MAX, u = -1;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // Add the picked vertex to the MST set
        inMST[u] = 1; // true

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of u
            // inMST[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST and its total cost
    printf("Edge \tWeight\n");
    for (int i = 0; i < V; i++) {
        if (i != startNode && parent[i] != -1) {
            printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
            totalWeight += graph[i][parent[i]];
        }
    }
    printf("Total cost of MST: %d\n", totalWeight);
}

int main() {
    int V, edge;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &edge);

    // Statically allocated 2D array for the adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Initialize the adjacency matrix with infinite values
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INT_MAX;
        }
    }

    // Input the edges with weights
    printf("Enter the edges with weights:\n");
    for (int i = 0; i < edge; i++) {
        int u, v, w;
        printf("EDGE %d\n", i + 1);
        printf("Source node: ");
        scanf("%d", &u);
        printf("End node: ");
        scanf("%d", &v);
        printf("Weight: ");
        scanf("%d", &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int startNode;
    printf("Enter the starting node for MST: ");
    scanf("%d", &startNode);

    // Function call
    primMST(graph, V, startNode);

    return 0;
}
