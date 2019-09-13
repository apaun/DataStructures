#include<iostream>

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void merge(int ar1[], int ar2[], int ar3[], int l1, int l2, int l3)
{
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    while(temp1 < l1 && temp2 < l2)
    {
        if (ar1[temp1] < ar2[temp2])
        {
            ar3[temp3++] = ar1[temp1++]; 
        }
        else
        {
            ar3[temp3++] = ar2[temp2++];
        }
    }

    while(temp1 < l1)
    {
        ar3[temp3++] = ar1[temp1++]; 
    }

    while(temp2 < l2)
    {
        ar3[temp3++] = ar2[temp2++];
    }
}

void mergeUtil(int ar[], int low, int mid, int high)
{
    int l1 = mid - low + 1; // This is length hence + 1
    int l2 = high - mid; // high - (mid + 1) + 1 => high - mid - 1 + 1

    int *ar1 = new int[mid - low + 1];
    int *ar2 = new int[high - mid];

    for (int i = 0; i < l1; i++)
    {
        ar1[i] = ar[low + i];
    }

    for (int i = 0; i < l2; i++)
    {
        ar2[i] = ar[mid + 1 + i];
    }

    int temp1 = 0;
    int temp2 = 0;
    int temp3 = low;
    while(temp1 < l1 && temp2 < l2)
    {
        if (ar1[temp1] < ar2[temp2])
        {
            ar[temp3++] = ar1[temp1++]; 
        }
        else
        {
            ar[temp3++] = ar2[temp2++];
        }
    }

    while(temp1 < l1)
    {
        ar[temp3++] = ar1[temp1++]; 
    }

    while(temp2 < l2)
    {
        ar[temp3++] = ar2[temp2++];
    }
}

void mergeSort(int ar[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(ar, low, mid);
        mergeSort(ar, mid + 1, high);
        mergeUtil(ar, low, mid, high);
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
    mergeSort(arr, 0, 5);
    pritnArray(arr, 5);

    int *arr1 = new int[3] { 1, 3, 5};
    int *arr2 = new int[5] { 2, 4, 6, 7, 8};
    int *arr3 = new int[8];
    merge(arr1, arr2, arr3, 3, 5, 8);
    pritnArray(arr3, 8);


}