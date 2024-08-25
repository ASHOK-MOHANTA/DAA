#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int callSearch(int A[], int N, int key)
{

    for (int i=0; i<N ;i++)
        if (A[i] == key)
            return i;
    return -1;
}

int main()
{
    int N;
    printf("Enter the element you want:");
    scanf("%d", &N);
    int A[N];
    for(int i=0;i<N; i++)
        A[i] = rand();
    
    printf("\nThe array is: \n");
    for(int i=0;i<N; i++)
       printf("%d, ",  A[i]);
    
    int key;
    printf("\nENter key: ");
    scanf("%d", &key);

    //-----------------------------------
    clock_t start, stop;
    start = clock();
    int R;
    for(int i = 0 ; i < 10000; i++)
        R = callSearch(A, N, key);
    stop = clock();
    //--------------------------------------
    if (R==-1)
        printf("\nKey element not found");
    else
        printf("\nKey element  found at  index %d", R);
    //------------------------------------------------

    double time_diff = (double) ((stop-start)/ CLOCKS_PER_SEC)/10000;
    printf("\nThe Time difference: %.15lf", time_diff);

}