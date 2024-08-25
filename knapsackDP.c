#include <stdio.h>

int max (int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}

void callKnapsackDP (int n, int c, int w[], int *p)
{
    int DP [n+1][c+1];


// ZERO initialisation
for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            DP[i][j] = 0; // Base case initialization
        }
    }
 /// ALGO --------------------


    for (int i=1; i<=n; i++)
        for (int j=1; j<=c; j++)
            if (j < w[i])
                DP[i][j]=DP[i-1][j];
            else
                DP[i][j]=max(DP[i-1][j],  DP[i-1][j-w[i]] + p[i]);

    printf("\n%d",  DP[n][c]); // max  profit

//------------------------  solution  vector -----

    int soln [n+1];
    for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=c; j++)
            if (DP[i][j]==DP[i-1][j])
                soln[i] = 0;
            else
                soln[i]=1;
        }
        
        printf ("\nSoln vector  is: \n");
        for (int i=1; i<=n; i++)
            printf("%d  ", soln[i]);


            
}


int main()
{
    int objects, capacity;
    printf("\nTotal objects: "); 
    scanf("%d",&objects);
    printf("\nTotal knapsack capacity: "); 
    scanf("%d",&capacity);

    int profits[objects+1], weights[objects+1];
    for(int i=1;i<=objects;i++)
    {
        printf("\nItem %d",i);
        printf("\nWeight: "); scanf("%d", &weights[i]);
        printf("\nProfit: "); scanf("%d", &profits[i]);
    }
   // int maxProfit = 
   callKnapsackDP (objects, capacity, weights, profits);
  //  printf ("\nMax profit : %d ", maxProfit);

}