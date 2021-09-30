/* Write a program to implement Max Heap */
// -Vatsal Parikh

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeap(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeap(arr, i, 0);
    }
}

void Array(int arr[], int n)
{

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {645, 231, 31, 87, 546, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    HeapSort(arr, n);

    printf("Sorted array is \n");
    Array(arr, n);
}
