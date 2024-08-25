#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void swap(int A[], int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int A[], int low, int high) {
    int pivot = A[low], i = low, j = high;
    while (i < j) {
        do {
            i++;
        } while (i <= high && A[i] < pivot);

        while (j >= low && A[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(A, i, j);
        }
    }
    swap(A, low, j);
    return j;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int j = partition(A, low, high);
        QuickSort(A, low, j - 1);
        QuickSort(A, j + 1, high);
    }
}

int main() {
    int A[MAX];
    int n;
    clock_t time_req;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        A[i] = rand()%50;
    }

    printf("\nUnsorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }

    time_req = clock();
    QuickSort(A, 0, n - 1);
    time_req = clock() - time_req;

    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }

    printf("\nTime taken: %.10f seconds\n", (double)time_req / CLOCKS_PER_SEC);

    return 0;
}
