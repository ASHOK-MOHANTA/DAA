#include<stdio.h>
#include<conio.h>
int find_FACT(int N)
{
    if(N==0|| N==1)
    return 1;
    else
    return N*find_FACT(N-1);
}
int main()
{
    printf("Enter a number");
    int num;
    scanf("%d",&num);
    if(num<0)
     printf("Invalid Input");
     else
     printf("\n %d! = %d", num, find_FACT(num));
}