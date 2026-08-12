#include <stdio.h>

int maxHeap[1000];
int minHeap[1000];

int maxSize = 0;
int minSize = 0;


// Insert into max heap
void insertMaxHeap(int value)
{
    int i = maxSize;
    maxHeap[maxSize++] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (maxHeap[parent] >= maxHeap[i])
            break;

        int temp = maxHeap[parent];
        maxHeap[parent] = maxHeap[i];
        maxHeap[i] = temp;

        i = parent;
    }
}


// Insert into min heap
void insertMinHeap(int value)
{
    int i = minSize;
    minHeap[minSize++] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (minHeap[parent] <= minHeap[i])
            break;

        int temp = minHeap[parent];
        minHeap[parent] = minHeap[i];
        minHeap[i] = temp;

        i = parent;
    }
}


// Remove maximum from max heap
int removeMax()
{
    int value = maxHeap[0];

    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if (right < maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest == i)
            break;

        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;

        i = largest;
    }

    return value;
}


// Remove minimum from min heap
int removeMin()
{
    int value = minHeap[0];

    minHeap[0] = minHeap[--minSize];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minSize && minHeap[left] < minHeap[smallest])
            smallest = left;

        if (right < minSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        int temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;

        i = smallest;
    }

    return value;
}


// Insert a new number
void insert(int num)
{
    if (maxSize == 0 || num <= maxHeap[0])
    {
        insertMaxHeap(num);
    }
    else
    {
        insertMinHeap(num);
    }

    // Balance the heaps

    if (maxSize > minSize + 1)
    {
        int value = removeMax();
        insertMinHeap(value);
    }

    if (minSize > maxSize)
    {
        int value = removeMin();
        insertMaxHeap(value);
    }
}


// Find median
float getMedian()
{
    if (maxSize == minSize)
    {
        return (maxHeap[0] + minHeap[0]) / 2.0;
    }

    return maxHeap[0];
}


int main()
{
    int numbers[] = {5, 10, 2, 8};
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        insert(numbers[i]);

        printf("After inserting %d, median = %.2f\n",
               numbers[i], getMedian());
    }

    return 0;
}
