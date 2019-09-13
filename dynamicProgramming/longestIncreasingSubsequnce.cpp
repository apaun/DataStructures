#include<iostream>
#include<string.h>

using namespace std;

int *lisMem;

int max(int n, int m)
{
    return n > m ? n : m;
}

int lis(int arr[], int n, int k, int prev)
{                                  
    if (k == n)    
        return 0;

    int res;
    if  (arr[k] >= prev)   
        res = max(1 + lis(arr, n, k + 1, arr[k]), lis(arr, n, k + 1, prev));
    else               
        res = lis(arr, n, k + 1, prev);
    return res;
}

int lisMemo(const int* arr, int n, int last)
{
    if (lisMem[n] != -1)
        return lisMem[n];

    int result = 0;
    if (n == 0)
        result = 0;
    else if (n == 1)
        result = 1;
    else if (arr[n - 1] > last)
        result = lisMemo(arr, n - 1, last);
    else
        result = max(lisMemo(arr, n - 1, last), 1 + lisMemo(arr, n - 1, arr[n - 1]));
    
    lisMem[n] = result;

    return result;
}

int lisBottomUp(const int* arr, int n)
{
    int *lisMemo = new int[n + 1];
    lisMemo[0] = 0;
    lisMemo[1] = 1;

    for(int i = 0; i <= n; i++)
    {
    }

}


int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr)/sizeof(arr[0]); 
    lisMem = new int[n + 1];

    for(int i = 0; i <= n; i++)
    {
        lisMem[i] = -1;
    }

    cout << "Length of lis is " <<  lis(arr, n, 0, 0) << endl;
    cout << "Length of lisMemo is " <<  lisMemo(arr, n, 15) << endl;
    return 0; 

}