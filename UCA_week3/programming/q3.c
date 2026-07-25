#include <stdio.h>

#define MAX 100000

void merge(int nums[], int index[], int tempNums[], int tempIndex[],
           int count[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (nums[j] < nums[i])
        {
            tempNums[k] = nums[j];
            tempIndex[k] = index[j];
            j++;
            k++;
            rightCount++;
        }
        else
        {
            count[index[i]] += rightCount;

            tempNums[k] = nums[i];
            tempIndex[k] = index[i];
            i++;
            k++;
        }
    }

    while (i <= mid)
    {
        count[index[i]] += rightCount;

        tempNums[k] = nums[i];
        tempIndex[k] = index[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        tempNums[k] = nums[j];
        tempIndex[k] = index[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
    {
        nums[i] = tempNums[i];
        index[i] = tempIndex[i];
    }
}

void mergeSort(int nums[], int index[], int tempNums[], int tempIndex[],
               int count[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(nums, index, tempNums, tempIndex, count, left, mid);
    mergeSort(nums, index, tempNums, tempIndex, count, mid + 1, right);

    merge(nums, index, tempNums, tempIndex, count, left, mid, right);
}

int main()
{
    int nums[] = {5, 2, 6, 1};

    int n = sizeof(nums) / sizeof(nums[0]);

    int index[MAX];
    int tempNums[MAX];
    int tempIndex[MAX];
    int count[MAX] = {0};

    for (int i = 0; i < n; i++)
        index[i] = i;

    mergeSort(nums, index, tempNums, tempIndex, count, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}
