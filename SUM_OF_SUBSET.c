#include <stdio.h>

void findSubsets(int arr[], int n, int subset[], int subsetSize, int total, int index, int targetSum) {
    if (total == targetSum) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    if (index == n || total > targetSum) {
        return;
    }

    // Include the current element
    subset[subsetSize] = arr[index];
    findSubsets(arr, n, subset, subsetSize + 1, total + arr[index], index + 1, targetSum);

    // Exclude the current element
    findSubsets(arr, n, subset, subsetSize, total, index + 1, targetSum);
}

int main() {
    int n, targetSum;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], subset[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    findSubsets(arr, n, subset, 0, 0, 0, targetSum);
    return 0;
}
