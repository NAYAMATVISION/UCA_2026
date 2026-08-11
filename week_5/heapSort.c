#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n - 1;

    
    while (size > 0) { 
        int temp = arr[0];
        arr[0] = arr[size];
        arr[size] = temp;

        size--;

        heapify(arr, size + 1, 0);
    }
}


void generateArray(int arr[], int n, int type) {
    for (int i = 0; i < n; i++) {
        if (type == 1) arr[i] = rand() % 100000; // Random
        else if (type == 2) arr[i] = i;          // Ascending
        else arr[i] = n - i;                     // Descending
    }
}

int main() {
    
    int validation_arr[] = {50, 55, 53, 52, 54};
    int val_n = 5;

    
    for (int i = val_n / 2; i >= 0; i--) {
        heapify(validation_arr, val_n, i);
    }

    heapSort(validation_arr, val_n);

    printf("\nSorted:   ");
    for(int i = 0; i < val_n; i++) printf("%d ", validation_arr[i]);
    printf("\n\n");


    
    srand(time(NULL));
    int N = 50000; // Size of the array for performance testing
    int *arr = (int *)malloc(N * sizeof(int));
    clock_t start, end;
    double cpu_time_used;

    printf("--- Performance Analysis (N = %d) ---\n", N);
    printf("Case\t\t\tExecution Time (Seconds)\n");
    printf("---------------------------------------------\n");

    // Case 1: Randomly ordered array
    generateArray(arr, N, 1);
    for (int i = N / 2; i >= 0; i--) heapify(arr, N, i);
    start = clock();
    heapSort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Random Array:\t\t%f\n", cpu_time_used);

    // Case 2: Array already sorted in ascending order
    generateArray(arr, N, 2);
    for (int i = N / 2; i >= 0; i--) heapify(arr, N, i);
    start = clock();
    heapSort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Ascending Array:\t%f\n", cpu_time_used);

    // Case 3: Array already sorted in descending order
    generateArray(arr, N, 3);
    for (int i = N / 2; i >= 0; i--) heapify(arr, N, i);
    start = clock();
    heapSort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Descending Array:\t%f\n", cpu_time_used);

    free(arr);
    return 0;
}

