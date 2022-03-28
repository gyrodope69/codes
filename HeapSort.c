#include <stdio.h>
#include <stdlib.h>

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    while (left <= n && left > arr[largest])
    {
        largest = left;
    }
    while (right <= n && right > arr[largest])
    {
        largest = right;
    }
    if (arr[largest] != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    for (i = n; i >= 1; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, n, i);
    }
}

void display_heap(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d", &arr[i]);
        printf("\n");
    }
}

int main()
{

    int arr[100];
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the element of the array");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d\n", &arr[i]);
    }
    heapSort(arr, n);
    display_heap(arr, n);
    return 0;
}