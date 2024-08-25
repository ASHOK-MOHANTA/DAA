#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item
{
    int profit, weight;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double  callKnapsackGreedy (int n, int capacity, vector<int>&profits, vector<int>&weights)
{
    vector <Item> objects (n+1);
    for (int i=1; i<=n; i++)
        objects[i]={profits[i], weights[i], (double)profits[i]/weights[i]};

    sort (objects.begin()+1, objects.end(), compare);

    double maxProfit=0;
    int remainingCap=capacity;
    vector<double> soln (n+1, 0);

    for (int i=1; i<=n; i++)
    {

       if (objects[i].weight<=remainingCap)
        {
            remainingCap -= objects[i].weight;
            maxProfit += objects[i].profit;
            soln[i]=1;
        }
        else
        {
            maxProfit+=objects[i].profit*((double) remainingCap/objects[i].weight);
            soln[i]=(double) remainingCap/objects[i].weight;
            break;
        }
    }

    cout<<"\nThe solution Vector: ";
    for (int i=1; i<=n; i++)
        {
            cout<<" " <<soln[i];
        }

        return maxProfit;

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

    double maxProfit = callKnapsackGreedy(n, capacity, profits, weights);

    cout<<"\nThe max profit is: "<<maxProfit;
}
