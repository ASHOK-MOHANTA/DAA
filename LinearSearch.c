#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int callSearch(int A[], int N)
{
    int key;
    printf("\nENter key: ");
    scanf("%d", &key);

    for (int i=0; i<N ;i++)
        if (A[i] == key)
            return i;
    return -1;
}

int main()
{
    int N;
    printf("Enter the number element you want:");
    scanf("%d", &N);
    int A[N];
    for(int i=0;i<N; i++)
        A[i] = rand()%500;
    
    printf("\nThe array is: \n");
    for(int i=0;i<N; i++)
       printf("%d, ",  A[i]);
    
    //-----------------------------------
    clock_t start, stop;
    start = clock();
    int R = callSearch(A, N);
    stop = clock();
    //--------------------------------------
    if (R==-1)
        printf("\nKey element not found");
    else
        printf("\nKey element  found at %d index", R);
    //------------------------------------------------

    double time_diff = (double) (stop-start)/ CLOCKS_PER_SEC;
    printf("\nThe Time difference: %lf", time_diff);

}