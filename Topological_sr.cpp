#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topologicalSourceRemoval(int nodes, int **graph)
{
// ============= INDEGREE ARRAY =================
    int inDegree[nodes+1]={0};
    for(int i=1;i<nodes+1;i++)
        for(int j=1;j<nodes+1;j++)
            if(graph[i][j])
                inDegree[j]++;
// ================ SOURCE QUEUE ====================
    queue<int> SourceQ;
    for(int i=1;i<nodes+1;i++)
        if(inDegree[i]==0)
            SourceQ.push(i);
//=================== SOLUTION VECTOR ================
    vector <int> SolutionVector;

    while(!SourceQ.empty())
    {   
        int node=SourceQ.front(); 
        SourceQ.pop();
        SolutionVector.push_back(node);
        for (int i=1; i<=nodes ; i++)
        {
            if(graph[node][i])
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                    SourceQ.push(i);
            }
        }
    }

// --------------- RESULT PRINTING -------------

    if (nodes!=SolutionVector.size())
        cout<<"\nCyclic graph given...";
    else
    {   
        cout<<"\nTopological sequence is\n::";
        for(int i=0; i<nodes; i++)
            cout<<SolutionVector[i]<<" ";
    }


}


int main()
{
    int nodes,edges;
    cout<<"Enter total nodes:";
    cin>>nodes;
    cout<<"Enter total edges:";
    cin>>edges;
    // make the graph
    int **graph=new int*[nodes+1];
    for(int i=1; i<nodes+1; i++)
        graph[i]=new int [nodes+1];
    
    // set graph to 0
    for(int i=1; i<nodes+1; i++)
        for(int j=1; j<nodes+1; j++)
            graph[i][j]=0;
    
    for(int i=1; i<=edges; i++)
    {
        int u, v;
        cout<<"For edge "<<i;
        cout<<"\nSource node: "; cin>>u;
         cout<<"\tDestination node: "; cin>>v;
         graph[u][v]=1;   
    }

    topologicalSourceRemoval(nodes, graph);
}