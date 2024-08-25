#include<stdio.h>
#include<conio.h>
int main()
{    
    int n;
    printf("Enter the size of matrix :");
    scanf("%d",&n);
    int MAtrix[n][n];
    printf("Enter the value of matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&MAtrix[i][j]);
        }
        
    }
    
    printf("Matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",MAtrix[i] [j]);
        }
        printf("\n");
    }
    

}