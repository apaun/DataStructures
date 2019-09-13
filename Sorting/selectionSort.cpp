#include<iostream>

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void selectionSort(int ar[], int length)
{
    for(int i = 0; i < length; i++)
    {
        int minIndex = i;
        for(int j = i; j < length; j++)
        {
            if (ar[j] < ar[minIndex])
                minIndex = j;
        }
        swap(&ar[minIndex], &ar[i]);
    }
}

void pritnArray(int ar[], int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int *arr = new int[5] {10, 2, 5, 1, 8 };
    pritnArray(arr, 5);
    selectionSort(arr, 5);
    pritnArray(arr, 5);
}