#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void mergeArrays(int A[], int Temp[], int low, int mid, int high);
void mergeSort(int A[], int Temp[], int low, int high);

int main() {
    int size;
    printf("Size of Array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Size exceeds the maximum allowed size of %d\n", MAX_SIZE);
        return 1;
    }

    int A[MAX_SIZE];
    int Temp[MAX_SIZE];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        A[i] = rand() % 3000;

    printf("\nUnsorted Array:\n");
    for (int i = 0; i < size; i++)
        printf("%d, ", A[i]);
    printf("\n");

    clock_t start, stop;
    double time_diff;
    start = clock();
    mergeSort(A, Temp, 0, size - 1);
    stop = clock();
    time_diff = ((double)(stop - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++)
        printf("%d, ", A[i]);
    printf("\nTime taken: %.15lf\n", time_diff);

    return 0;
}

void mergeArrays(int A[], int Temp[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            Temp[k++] = A[i++];
        } else {
            Temp[k++] = A[j++];
        }
    }

    while (i <= mid) {
        Temp[k++] = A[i++];
    }

    while (j <= high) {
        Temp[k++] = A[j++];
    }

    for (i = low; i <= high; i++) {
        A[i] = Temp[i];
    }
}

void mergeSort(int A[], int Temp[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(A, Temp, low, mid);
        mergeSort(A, Temp, mid + 1, high);

        mergeArrays(A, Temp, low, mid, high);
    }
}
