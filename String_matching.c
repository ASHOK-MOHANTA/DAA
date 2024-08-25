#include <stdio.h>
#include <string.h>

// Function to perform brute force string matching
int bruteForceStringMatch(const char* pattern, const char* text) {
    int m = strlen(pattern);
    int n = strlen(text);
    int flag=0, i, j;

    for (i = 0; i <= n - m; ++i) {
        
        for (j = 0; j < m; ++j)
            if (text[i + j] != pattern[j])
                break;

        if (j == m)
        {
            flag = 1;
            return i;
        }

    }


    if (flag == 0)
        return -1;
}

int main() {
    char pattern[100], filename[100];
    
    // Input pattern to search
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    // Input file name
    strcpy(filename, "E:/ASHOK/Desktop/DAAA/s.txt");

//============== FILE HANDLING ============== //

    // Read file
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf( "Error opening file!\n");
        return 1;
    }

    char line[100];
    char text[1000] = "";
    while (fgets(line, sizeof(line), file) != NULL)
        strcat(text, line);

    int R = bruteForceStringMatch(pattern, text);

    fclose(file);

//========================================
// S = S + i



    if (R==-1)
        printf("\nSample text not found");
    else
        printf("\nSample found at %d index.", R);

    return 0;
}