#include<stdio.h>

void callKnapsack(int o, int c, int w[], int *p)
{
    int remCapacity=c;
    float maxProfit=0, soln[o+1];
    for (int i=1; i<=o;i++)
        soln[i]=0;
    
    for (int i=1; i<=o; i++)
        {
            if (w[i]>remCapacity)
            {
                soln[i] = remCapacity/(float)w[i];
                remCapacity=0;
            }
        
        else
        {
            remCapacity-=w[i];
            soln[i]=1;
        }
        }
    
    printf("\n===");
    for (int i=1; i<=o; i++)
        printf ("%.4f,  ", soln[i]);

    for (int i=1; i<=o; i++)
        maxProfit+= soln[i] * p[i];
    printf ("\nMax profit : %.4f", maxProfit);

}


int main()
{
    int capacity, objects;
    printf("\nCapacity: "); scanf ("%d", &capacity);
    printf("\nObjects: "); scanf ("%d", &objects);

    int weights [objects+1], profits[objects+1];

    for (int i=1; i<=objects; i++)
    {
        printf("\nFor item %d", i);
        printf ("\nweight: "); scanf("%d", &weights[i]);
        printf ("\nprofitt: "); scanf("%d", &profits[i]);
    }

    callKnapsack(objects, capacity, weights, profits);

}
