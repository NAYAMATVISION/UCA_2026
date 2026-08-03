#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

void quickSelect(int arr[], int low, int high, int k)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        if(p == k)
            return;
        else if(k < p)
            quickSelect(arr, low, p - 1, k);
        else
            quickSelect(arr, p + 1, high, k);
    }
}

void randomArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = rand();
}

double elapsed_ms(clock_t start, clock_t end)
{
    return ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
}

int main()
{
    srand(time(NULL));

    int sizes[] = {
        1000,
        5000,
        10000,
        20000,
        50000,
        100000,
        200000,
        500000
    };

    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("-----------------------------------------\n");
    printf(" Dataset Size\tAverage Time (ms)\n");
    printf("-----------------------------------------\n");

    for(int s = 0; s < numSizes; s++)
    {
        int n = sizes[s];
        double totalTime = 0.0;

        for(int trial = 0; trial < 20; trial++)
        {
            int *arr = (int *)malloc(n * sizeof(int));

            randomArray(arr, n);

            int k = n / 10;

            clock_t start = clock();

            quickSelect(arr, 0, n - 1, k - 1);

            clock_t end = clock();

            totalTime += elapsed_ms(start, end);

            free(arr);
        }

        printf("%10d\t%10.4f\n", n, totalTime / 20.0);
    }

    return 0;
}
