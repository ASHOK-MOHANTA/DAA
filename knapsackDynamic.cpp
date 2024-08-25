#include<iostream>
#include<vector>
using namespace std;

int callKnapsackDP(int n, int capacity, vector<int>&weights, vector<int>&profits)
{
    vector<vector<int>> DP (n+1, vector<int>(capacity+1, 0));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=capacity; j++)
            if(weights[i] > j)
                DP[i][j]=DP[i-1][j];
            else
                DP[i][j]=max(DP[i-1][j],  DP[i-1][j - weights[i]] + profits[i]);


    cout<<"\nThe Solution vector is: ";
    vector<int>soln (n+1,0);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=capacity; j++)
            if (DP[i][j]==DP[i-1][j])
                soln[i]=0;
            else
                soln[i]=1;

    for (int i=1; i<=n; i++)
        cout<<soln[i]<<", ";
    
    return DP[n][capacity];

    
}


int main()
{   
    int n, capacity;
    cout<<"Total objects: "; cin>> n;
    cout<<"\nKnapsack capacity: "; cin>>capacity;

    vector<int> profits(n+1), weights(n+1);

    cout<<"\nEnter the profit and weight for each item: ";
    for(int i=1; i<=n; i++)
    {
        cout<<"\nITEM "<<i<<",\nWeight: "; cin>>weights[i];
        cout<<"\tProfit: "; cin>>profits[i];
    }

    cout<<"\n======================================"<<endl;
   
    int maxP=callKnapsackDP(n, capacity, weights, profits);
     cout<<"Max Profit is:: "<< maxP;

}