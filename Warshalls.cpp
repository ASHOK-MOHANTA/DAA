#include<iostream>
#include<vector>
using namespace std;

void callWarshall(vector<vector<int>>& graph, int nodes)
{
    vector<vector<int>> reach(nodes + 1, vector<int>(nodes + 1, 0));
    for (int i = 1; i <= nodes; i++)
        for (int j = 1; j <= nodes; j++)
            reach[i][j] = graph[i][j];

    for (int k = 1; k <= nodes; k++)
        for (int i = 1; i <= nodes; i++)
            for (int j = 1; j <= nodes; j++)
                if (reach[i][k] && reach[k][j])
                    reach[i][j] = 1;

    cout << "\nThe transitive closure of the graph is: " << endl;
    for (int i = 1; i <= nodes; ++i) {
        for (int j = 1; j <= nodes; ++j) {
            cout << reach[i][j] << " ";
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

    // Initialize adjacency list
    vector<vector<int>> adjList(nodes + 1, vector<int>(nodes + 1, 0));

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cout << "\nEnter edge " << i << endl;
        cout << "\nStart node: "; cin >> u;
        cout << "\nEnd node: "; cin >> v;
        adjList[u][v] = 1; 
        
    }

    callWarshall(adjList, nodes);
    return 0;
}
