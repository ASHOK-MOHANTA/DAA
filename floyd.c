#include<stdio.h>
#include<conio.h>

int min (int a, int b)
{
    if (a<b)
        return a;
    else
        return b;
}

void callFloyd (int size, int matrix [size][size])
{
    int duplicateM[size][size];

// copy original M --------
    for (int i=0;i<size;i++)
      for (int j=0;j<size;j++)
        duplicateM[i][j]=matrix[i][j];
// --------- algo -----------
    for (int k=0; k<size; k++)
        for (int i=0;i<size;i++)
            for (int j=0;j<size;j++)
                duplicateM[i][j]=min(duplicateM[i][j], duplicateM[i][k]+duplicateM[k][j]);


    printf("\nTransitive closure is:\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            printf("%d  ",duplicateM[i][j]);
        printf("\n");
    }
}


int main()
{   printf("Enter the size Of Matrix:\n");
    int size;
    scanf("%d",&size);
    int matrix[size][size];
    
    printf("Enter the adjecency matrix:\n");
    for (int i=0;i<size;i++)
      for (int j=0;j<size;j++)
        scanf("%d",&matrix[i][j]);  
         
    // -----------  print the adj. matrix
    printf("Your Adjecency matrix:\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            printf("%d  ",matrix[i][j]);
        printf("\n");
    }

    callFloyd (size, matrix);

}

