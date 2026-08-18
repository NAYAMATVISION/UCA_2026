#include <stdio.h>

int findFourTimes(int arr[], int n)
{
    int result = 0;

    for (int bit = 0; bit < 32; bit++)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] & (1 << bit))
            {
                count++;
            }
        }

        if (count % 3 != 0)
        {
            result = result | (1 << bit);
        }
    }

    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    int answer = findFourTimes(arr, n);

    printf("Number repeated 4 times: %d\n", answer);

    return 0;
}
