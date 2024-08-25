// #include <iostream>
// #include <limits>
// #include <vector>

// const int INF = std::numeric_limits<int>::max();

// void dijkstra(const std::vector<std::vector<int>>& graph, int src, int V) {
//   // Create a vector to store distances from the source
//   std::vector<int> dist(V, INF);
//   dist[src] = 0;

//   // Create a vector to keep track of processed vertices
//   std::vector<bool> processed(V, false);

//   // Find shortest path for all vertices
//   for (int count = 0; count < V - 1; count++) {
//     // Pick the minimum distance vertex from the unprocessed set
//     int u = -1;
//     for (int i = 0; i < V; i++) {
//       if (!processed[i] && (u == -1 || dist[i] < dist[u])) {
//         u = i;
//       }
//     }

//     // Mark the picked vertex as processed
//     processed[u] = true;

//     // Update distances of adjacent vertices
//     for (int v = 0; v < V; v++) {
//       // Update dist[v] only if is not in processed set and there is an edge from
//       // u to v, and the total weight of path from src to v through u is smaller
//       // than current value of dist[v]
//       if (graph[u][v] != 0 && !processed[v] && dist[u] + graph[u][v] < dist[v]) {
//         dist[v] = dist[u] + graph[u][v];
//       }
//     }
//   }

//   // Print the constructed distance vector
//   std::cout << "Vertex \t Distance from Source" << std::endl;
//   for (int i = 0; i < V; i++) {
//     std::cout << i << "\t" << dist[i] << std::endl;
//   }
// }

// int main() {
//   int V, E;
//   std::cin >> V >> E;

//   // Create adjacency matrix
//   std::vector<std::vector<int>> graph(V, std::vector<int>(V, 0));
//   for (int i = 0; i < E; i++) {
//     int u, v, w;
//     std::cin >> u >> v >> w;
//     graph[u][v] = w;
//   }

//   int src;
//   std::cout << "Enter source vertex: ";
//   std::cin >> src;

//   dijkstra(graph, src, V);

//   return 0;
// }



#include<algorithm>
#include<iostream>
#include<vector>
#include <climits>
using namespace std;


void callDijkstras(vector<vector<int>> &graph, int nodes, int src)
{
    vector<int> dist (nodes+1, INT_MAX);
    dist[src]=0;
    vector<bool>visited (nodes+1, false);

    for (int c=0; c<nodes; c++)
    {   
        int u=-1;
        for (int i=1; i<=nodes; i++)
            if(!visited[i] && (u==-1 || dist[i]<dist[u]))
                u=i; 

        visited[u]=true;

        for (int v=1; v<=nodes; v++)
            if (graph[u][v]!=INT_MAX && !visited[v] )
                dist[v]=min(dist[v], dist[u] + graph[u][v]);

    }

    cout << "Vertex \t Distance from Source node" << std::endl;
    for (int i = 1; i <= nodes; i++)
    if (dist[i]==INT_MAX) 
        cout << i << "\t" << "INF" << std::endl;
    else
        cout << i << "\t" << dist[i] << std::endl;

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

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    callDijkstras(adjMatrix, nodes, src);
    return 0;
}