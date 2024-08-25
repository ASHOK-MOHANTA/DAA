#include<stdio.h>
#include<conio.h>

void callWarshall (int size, int matrix[size][size])
{
    int duplicateM[size][size];

// copy original M --------
    for (int i=0;i<size;i++)
      for (int j=0;j<size;j++)
        duplicateM[i][j]=matrix[i][j];


/// ------- ALGO --------------
    for (int k=0; k<size; k++)
        for (int i=0;i<size;i++)
            for (int j=0;j<size;j++)
                if (duplicateM[i][k] && duplicateM [k][j])
                    duplicateM[i][j]=1;


    printf("\nTransitive closure Matrix:\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            printf("%d  ",duplicateM[i][j]);
        printf("\n");
    }


}

int main()
{
    printf("Enter the size of matrix \n");
    int size;
    scanf("%d",&size);
    int matrix[size][size];
    
    printf("Enter the adjecency matrix: \n");
    for (int i=0;i<size;i++)
      for (int j=0;j<size;j++)
        scanf("%d",&matrix[i][j]);  
         
    // -----------  print the adj. matrix
    printf("Your Adjecency Matrix\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            printf("%d  ",matrix[i][j]);
        printf("\n");
    }

    callWarshall (size, matrix);
}

//-------------------------------------------------------
