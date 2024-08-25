#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void Selectionsort(int A[],int N)
{
    
    for(int i=0;i<N;i++)
    {
        int min=i, tmp;
        for(int j=i+1;j<N;j++)
        {
            if(A[min]>A[j])
                min=j;
        }

        tmp = A[min];
        A[min]= A[i];
        A[i]=tmp;        

    }

    printf("\nSorted array: ");
    for(int i=0;i<N;i++)
        printf("%d, ", A[i]);
}

int main()
{
    int N;
    printf("Enter the number of element you want:");
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;i++)
        A[i]=rand()%1000;
    printf("\n Unsorted array: ");
    for(int i=0;i<N;i++)
        printf("%d, ", A[i]);
    //=============================================================================
    clock_t start, stop;
    start=clock();
    Selectionsort(A,N);
    stop=clock();

    double time_diff=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nTime difference is %lf", time_diff);

}
