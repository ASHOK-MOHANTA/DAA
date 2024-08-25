#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void InsertionSort(int A[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int item = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > item) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = item;
    }
}

int main() {
    int A[MAX];
    int n;
    clock_t time_req;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        A[i] = rand() % 50;
    }

    printf("\nArray Inserted\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }

    time_req = clock();
    InsertionSort(A, n);
    time_req = clock() - time_req;

    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }

    printf("\nTime taken: %.10f seconds\n", (double)time_req / CLOCKS_PER_SEC);

    return 0;
}
