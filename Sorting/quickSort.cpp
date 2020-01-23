#include<iostream>

void pritnArray(int ar[], int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for(int j = low; j <= high - 1; j++)
    {
        if(arr[j] < pivot)
        {
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;

}

void quickSortAlogo(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSortAlogo(arr, low, pi - 1);
        quickSortAlogo(arr, pi + 1, high);
    }
}

int main()
{
    int *arr = new int[5] {10, 2, 5, 1, 8 };
    pritnArray(arr, 5);
    quickSortAlogo(arr, 0, 4);
    pritnArray(arr, 5);
}