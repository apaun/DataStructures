#include<iostream>

void pritnArray(int ar[], int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSortAlgo(int arr[], int length)
{
    for(int i = 1; i < 5; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1 ] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int *arr = new int[5] {10, 2, 5, 1, 8 };
    pritnArray(arr, 5);
    insertionSortAlgo(arr, 5);
    pritnArray(arr, 5);
}