#include<iostream>

using namespace std;

unsigned long long *fibMemoization;

const long MOD = 1000000007;

template <typename T>
T fibRecursive(T n)
{
    if(n == 0 || n == 1)
        return n;
    else
        return fibRecursive(n - 1) + fibRecursive(n - 2);
}

template <typename T>
T fibMemo(T n)
{
    if(fibMemoization[n] != -1)
        return fibMemoization[n];

    T result = 0;
    if(n == 0 || n == 1)
        result = n;
    else
        result = fibMemo(n - 1) + fibMemo(n - 2);

    fibMemoization[n] = result;
    result;
}

template <typename T>
T fitTopDown(T n)
{
    T *fibMemo = new T[n + 1];

    fibMemo[0] = 0;
    fibMemo[1] = 1;

    for(T i = 2; i <= n; i++)
    {
        fibMemo[i] = fibMemo[i - 1] + fibMemo[i - 2];
    }

    return fibMemo[n];
}

template <typename T>
void multiply(T F[2][2], T M[2][2])
{
    T c00 = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % MOD;
    T c01 = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % MOD;
    T c10 = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % MOD ;
    T c11 = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % MOD;

    F[0][0] = c00;
    F[0][1] = c01;
    F[1][0] = c10;
    F[1][1] = c11;

}

template <typename T>
void power(T F[2][2], T n)
{
    if(n == 0 || n == 1)
        return;

    T M[2][2] = {{ 1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F , F);

    if (n % 2 == 1)
        multiply(F, M);
}

template <typename T>
T fibMatrixExponential(T n)
{
    if (n == 0)
        return 1;

    T Fib[2][2] = {{ 1, 1}, {1, 0}};

    power(Fib, n - 1);

    return Fib[0][0] % MOD;
}


int main()
{
    unsigned long long n;
    cout << "Enter number : ";
    cin >> n;

    fibMemoization = new unsigned long long[n];

   // cout << "Fib Recursive is " << fibRecursive(n) << endl;
    //cout << "Fib Memo is " << fibMemo(n) << endl;
    cout << "Fib Top Down is " << fitTopDown<unsigned long long>(n) << endl;
    cout << "Fib Matrix Exponential is " << fibMatrixExponential<unsigned long long>(n) << endl;


    return 0;
}