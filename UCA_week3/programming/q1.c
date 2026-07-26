#include <stdio.h>

#define MAX 100000

int temp[MAX];

long long merge(int arr[], int left, int mid, int right)
{
    long long count = 0;

    // Count significant reverse pairs
    int j = mid + 1;

    for (int i = left; i <= mid; i++)
    {
        while (j <= right && (long long)arr[i] > 2LL * arr[j])
            j++;

        count += (j - (mid + 1));
    }

    // Merge the two sorted halves
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

long long mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;

    long long count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);

    count += merge(arr, left, mid, right);

    return count;
}

int main()
{
    int arr[] = {1, 3, 2, 3, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%lld\n", mergeSort(arr, 0, n - 1));

    return 0;
}
