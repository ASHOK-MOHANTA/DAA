// #include <stdio.h>

// #define n  // define n as the number of vertices in your graph
// #define INF 999 // define INF as the infinity value for comparison

// int cost[n][n]; // assuming cost[][] is the adjacency matrix of the graph

// int prims() {
//     int i, j, k, l, v, mincost, Near[n], d[n], min;
//     int t[n - 1][2];

//     // Initialization
//     mincost = 0;
//     min = INF;
//     for (i = 0; i < n; i++) {
//         Near[i] = 0; // Initialize Near[] array
//         d[i] = cost[0][i]; // Initialize distance array with cost from vertex 0
//     }

//     // Find minimum cost edge
//     for (i = 1; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             if (d[j] < min && Near[j] == 0) {
//                 min = d[j];
//                 k = j;
//             }
//         }
//         Near[k] = 1; // Include vertex k in MST
//         mincost += min; // Add minimum edge cost to the total cost
//         min = INF;

//         // Store the edge (k, Near[k]) in the MST
//         t[i - 1][0] = k;
//         t[i - 1][1] = Near[k];

//         // Update distance array and find new minimum cost edge
//         for (j = 0; j < n; j++) {
//             if (cost[k][j] < d[j] && Near[j] == 0) {
//                 d[j] = cost[k][j];
//             }
//         }
//     }

//     return mincost;
// }

// int main() {
//     int mincost;
//     // Call prims() function to get the minimum cost
//     mincost = prims();
//     printf("Minimum cost of spanning tree: %d\n", mincost);
//     printf("Edges in the minimum cost spanning tree:\n");
//     for (int i = 0; i < n - 1; i++) {
//         printf("%d -- %d\n", t[i][0], t[i][1]);
//     }
//     return 0;
// }
//---------------------------------------------------------------------
// #include <stdio.h>

// #define n 5  
// #define INF 999 
// int cost[n][n]; 

// int prims(int t[][2]) {
//     int i, j, k, mincost, Near[n], d[n], min;
//     mincost = 0;
//     min = INF;
//     for (i = 0; i < n; i++) {
//         Near[i] = 0; 
//         d[i] = cost[0][i];
//     } 
//     for (i = 1; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             if (d[j] < min && Near[j] == 0) {
//                 min = d[j];
//                 k = j;
//             }
//         }
//         Near[k] = 1; 
//         mincost += min; 
//         min = INF;
//         t[i - 1][0] = k;
//         t[i - 1][1] = Near[k];
//         for (j = 0; j < n; j++) {
//             if (cost[k][j] < d[j] && Near[j] == 0) {
//                 d[j] = cost[k][j];
//             }
//         }
//     }
//     return mincost;
// }

// int main() {
//     int mincost, t[n - 1][2], i;
//     mincost = prims(t);
//     printf("Minimum cost of spanning tree: %d\n", mincost);
//     printf("Edges in the minimum cost spanning tree:\n");
//     for (i = 0; i < n - 1; i++) {
//         printf("%d -- %d\n", t[i][0], t[i][1]);
//     }
//     return 0;
// }
//------------------------------------------------------------------------------
// #include <stdio.h>

// #define MAX_SIZE 5
// #define INF 999

// int prims(int cost[MAX_SIZE][MAX_SIZE], int n, int t[][2]) {
//     int i, j, k, mincost, Near[MAX_SIZE], d[MAX_SIZE], min;
//     mincost = 0;
//     min = INF;
//     for (i = 0; i < n; i++) {
//         Near[i] = 0; 
//         d[i] = cost[0][i];
//     } 
//     for (i = 1; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             if (d[j] < min && Near[j] == 0) {
//                 min = d[j];
//                 k = j;
//             }
//         }
//         Near[k] = 1; 
//         mincost += min; 
//         min = INF;
//         t[i - 1][0] = k;
//         t[i - 1][1] = Near[k];
//         for (j = 0; j < n; j++) {
//             if (cost[k][j] < d[j] && Near[j] == 0) {
//                 d[j] = cost[k][j];
//             }
//         }
//     }
//     return mincost;
// }

// int main() {
//     int cost[MAX_SIZE][MAX_SIZE], n, mincost, t[MAX_SIZE - 1][2], i, j;
    
//     printf("Enter the number of nodes (max %d): ", MAX_SIZE);
//     scanf("%d", &n);

//     printf("Enter the cost adjacency matrix (%d x %d):\n", n, n);
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             scanf("%d", &cost[i][j]);
//             if (i == j) // Setting diagonal elements to infinity
//                 cost[i][j] = INF;
//         }
//     }

//     mincost = prims(cost, n, t);

//     printf("Minimum cost of spanning tree: %d\n", mincost);
//     printf("Edges in the minimum cost spanning tree:\n");
//     for (i = 0; i < n - 1; i++) {
//         printf("%d -- %d\n", t[i][0], t[i][1]);
//     }
//     return 0;
// }
#include <stdio.h>

#define MAX_SIZE 5
#define INF 999

int prims(int cost[MAX_SIZE][MAX_SIZE], int n, int t[][2]) {
    int i, j, k, mincost = 0, min, Near[MAX_SIZE], d[MAX_SIZE];
    
    for (i = 0; i < n; i++) {
        Near[i] = 0; 
        d[i] = cost[0][i];
    } 
    
    Near[0] = -1; // Mark the starting vertex as visited
    
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (d[j] < min && Near[j] == 0) {
                min = d[j];
                k = j;
            }
        }
        Near[k] = -1; // Mark the selected vertex as visited
        mincost += min;
        
        t[i - 1][0] = k;
        t[i - 1][1] = -1;  // Initial value to store the edge, will be updated in the next loop
        
        for (j = 0; j < n; j++) {
            if (cost[k][j] < d[j] && Near[j] == 0) {
                d[j] = cost[k][j];
                Near[j] = k;
            }
        }
    }
    
    // Update the second vertex of each edge in t[][]
    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (Near[j] == i) {
                t[i - 1][1] = j;
                break;
            }
        }
    }

    return mincost;
}

int main() {
    int cost[MAX_SIZE][MAX_SIZE], n, mincost, t[MAX_SIZE - 1][2] = {0}, i, j;
    
    printf("Enter the number of nodes (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j) // Setting diagonal elements to infinity
                cost[i][j] = INF;
        }
    }

    mincost = prims(cost, n, t);

    printf("Minimum cost of spanning tree: %d\n", mincost);
    printf("Edges in the minimum cost spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d -- %d\n", t[i][0], t[i][1]);
    }
    return 0;
}



