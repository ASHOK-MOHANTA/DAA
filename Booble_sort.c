#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void Bubblesort(int A[],int N)
{
    int tmp;
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                tmp=A[j];
                A[j]=A[j+1];
                A[j+1]=tmp;
            }
        }
    }

    printf("\nSorted array: ");
    for(int i=0;i<N;i++)
        printf("%d, ", A[i]);
}

int main()
{
    int N;
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
    Bubblesort(A,N);
    stop=clock();

    double time_diff=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\nTime difference is %.15lf", time_diff);

}
