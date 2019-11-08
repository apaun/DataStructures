#include <iostream>

using namespace std;

typedef void (*Callback) (int);

void printNumber(int n)
{
    cout << n << endl;
}

void callCallback(Callback cb, int num)
{
    (*cb)(num);
}

int AddNumber(int n, int n2)
{
    return n + n2;
}

int main()
{
    callCallback(&printNumber, 10);
    callCallback(&printNumber, AddNumber(10, 20));
    return 0;
}
