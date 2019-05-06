#include<iostream>

using namespace std;

int *fibMemoization;

int fibRecursive(int n)
{
    if(n == 0 || n == 1)
        return n;
    else
        return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibMemo(int n)
{
    if(fibMemoization[n] != -1)
        return fibMemoization[n];

    int result = 0;
    if(n == 0 || n == 1)
        result = n;
    else
        result = fibRecursive(n - 1) + fibRecursive(n - 2);

    fibMemoization[n] = result;
    result;
}

int fitTopDown(int n)
{
    int *fibMemo = new int[n];

    fibMemo[0] = 0;
    fibMemo[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        fibMemo[i] = fibMemo[i - 1] + fibMemo[i - 2];
    }

    return fibMemo[n];
}


int main()
{
    int n = 9;

    fibMemoization = new int[n];

    for(int i = 0; i <= n; i++)
    {
        fibMemoization[i] = -1;
    }

    cout << "Fib Recursive is " << fibRecursive(n) << endl;
    cout << "Fib Memo is " << fibMemo(n) << endl;
    cout << "Fib Top Down is " << fitTopDown(n) << endl;


    return 0;
}