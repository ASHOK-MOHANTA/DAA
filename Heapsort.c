#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int A[], int size, int parent) {
    int largest = parent, leftCh = 2 * parent + 1, rightCh = 2 * parent + 2;

    if (leftCh < size && A[leftCh] > A[largest])
        largest = leftCh;
    if (rightCh < size && A[rightCh] > A[largest])
        largest = rightCh;

    if (largest != parent) {
        swap(&A[parent], &A[largest]);
        heapify(A, size, largest);
    }
}

void buildHeap(int A[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(A, size, i);
}

void heapSort(int A[], int size) {
    buildHeap(A, size);

    for (int i = size - 1; i >= 0; i--) {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);  // Use the updated size here
    }
}

int main() {
    int N;
    printf("\nArray size: ");
    scanf("%d", &N);
    int *Arr = (int *)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++)
        Arr[i] = rand() % 45;

    printf("\nThe input array:");
    for (int i = 0; i < N; i++)
        printf(" %d", Arr[i]);

    heapSort(Arr, N);

    printf("\nThe sorted array is:");
    for (int i = 0; i < N; i++)
        printf(" %d", Arr[i]);

    free(Arr);  // Free the allocated memory
    return 0;
}
