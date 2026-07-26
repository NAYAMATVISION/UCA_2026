#include <stdio.h>

#define MAX 100000

long long merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    long long inv = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

long long mergeSort(int arr[], int temp[], int left, int right)
{
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;

    long long inv = 0;

    inv += mergeSort(arr, temp, left, mid);
    inv += mergeSort(arr, temp, mid + 1, right);

    inv += merge(arr, temp, left, mid, right);

    return inv;
}

int main()
{
    int arr[] = {1, 2, 4, 1, 3, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[MAX];

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("%lld\n", inversions);

    return 0;
}
