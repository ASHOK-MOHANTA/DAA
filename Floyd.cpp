#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>
using namespace std;

void callFloyd(vector<vector<int>>& graph, int nodes)
{
    vector<vector<int>> dist = graph;

    // Floyd's Algorithm
    for (int k = 1; k <= nodes; k++)
        for (int i = 1; i <= nodes; i++)
            for (int j = 1; j <= nodes; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX )
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

    cout << "\nThe shortest distances between every pair of vertices: " << endl;
    for (int i = 1; i <= nodes; ++i) {
        for (int j = 1; j <= nodes; ++j) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}




int main()
{
    int edges, nodes;
    cout << "\nEnter the number of nodes: ";
    cin >> nodes;
    cout << "\nEnter the number of edges: ";
    cin >> edges;

    // Initialize adjacency matrix with INF for unconnected nodes
    vector<vector<int>> adjMatrix(nodes + 1, vector<int>(nodes + 1, INT_MAX));

    cout << "\nEnter edges and weights (from to weight): \n";
    for (int i = 1; i <= edges; i++)
    {
        int u, v, weight;
        cout << "\nEnter edge " << i << endl;
        cout << "\nStart node: "; cin >> u;
        cout << "\nEnd node: "; cin >> v;
        cout << "\nWeight: "; cin >> weight;
        adjMatrix[u][v] = weight;
    }

    // Set diagonal elements to 0
    for (int i = 1; i <= nodes; i++)
        adjMatrix[i][i] = 0;

    callFloyd(adjMatrix, nodes);
    return 0;
}
