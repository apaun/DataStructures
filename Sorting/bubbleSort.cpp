#include<iostream>

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void bubbleSort(int ar[], int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - i; j++)
        {
            if (ar[j] > ar[j + 1])
                swap(&ar[j], &ar[j + 1]);
        }
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
    bubbleSort(arr, 5);
    pritnArray(arr, 5);
}