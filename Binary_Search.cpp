#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int callsearch(int *A,int low,int high,int key)
{
    if(low>high)

        return -1;

    int mid = low +(high-low)/2;
    if(key==A[mid])
    return mid;
    else if(key>A[mid])
    return callsearch(A,mid+1,high,key);
    else
    return callsearch(A,low,mid-1,key);
}
int main()
{
    int N,key,R;
    printf("Size of array:");
    scanf("%d",&N);
    int *A=new int[N];
    for(int i=0;i<N;i++)
    A[i]=rand();
    sort(A,A+N);
    printf("\n The array is:");
    for(int i=0;i<N;i++)
    printf("%d  ,",A[i]);
    printf("\nEnter key element:");
    scanf("%d",&key);
    clock_t start,stop;
    start=clock();
    for(int i=0;i<3000;i++)
    R=callsearch(A,0,N-1,key);
    stop=clock();
    double time_diff=(double)(stop-start)/CLOCKS_PER_SEC;
    printf("\n Time taken :%dlf",time_diff/3000);
    if(R==-1)
    printf("\n No key found");
    else
    printf("\n key found at index %d",R);
}