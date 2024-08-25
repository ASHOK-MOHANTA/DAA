#include <stdio.h>
#include <stdlib.h>

int callKnapsackDP(int n, int capacity, int weights[], int profits[])
{
    int DP[n+1][capacity+1];

    // Initialize DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            DP[i][j] = 0;
        }
    }

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weights[i] > j)
            {
                DP[i][j] = DP[i-1][j];
            }
            else
            {
                DP[i][j] = (DP[i-1][j] > (DP[i-1][j - weights[i]] + profits[i])) ? DP[i-1][j] : (DP[i-1][j - weights[i]] + profits[i]);
            }
        }
    }

    // Trace back to find the solution
    int soln[n+1];
    for (int i = 0; i <= n; i++)
    {
        soln[i] = 0;
    }
    
    int remainingCapacity = capacity;
    for (int i = n; i > 0 && remainingCapacity > 0; i--)
    {
        if (DP[i][remainingCapacity] != DP[i-1][remainingCapacity])
        {
            soln[i] = 1;
            remainingCapacity -= weights[i];
        }
    }

    printf("\nThe Solution vector is: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d, ", soln[i]);
    }
    printf("\n");

    return DP[n][capacity];
}

int main()
{   
    int n, capacity;
    printf("Total objects: "); 
    scanf("%d", &n);
    printf("\nKnapsack capacity: "); 
    scanf("%d", &capacity);

    int profits[n+1], weights[n+1];

    printf("\nEnter the profit and weight for each item: ");
    for(int i = 1; i <= n; i++)
    {
        printf("\nITEM %d,\nWeight: ", i); 
        scanf("%d", &weights[i]);
        printf("\tProfit: "); 
        scanf("%d", &profits[i]);
    }

    printf("\n======================================\n");
   
    int maxP = callKnapsackDP(n, capacity, weights, profits);
    printf("Max Profit is: %d\n", maxP);

    return 0;
}
