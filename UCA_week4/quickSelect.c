#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int p = partition(arr, low, high);

        if (p == k)
            return;
        else if (p > k)
            quickSelect(arr, low, p - 1, k);
        else
            quickSelect(arr, p + 1, high, k);
    }
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k > n || k <= 0) {
        printf("Invalid K\n");
        free(arr);
        return 0;
    }

    quickSelect(arr, 0, n - 1, k - 1);

    printf("Smallest %d elements:\n", k);
    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);

    printf("\n");

    free(arr);
    return 0;
}
