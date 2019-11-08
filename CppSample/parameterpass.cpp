#include <iostream>

using namespace std;

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl; 
}

void swapPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n1 = 10;
    int n2 = 20;

    swap(n1, n2);

    swapPointer(&n1, &n2);
    cout << n1 << " " << n2 << endl;

    swapReference(n1, n2);
    cout << n1 << " " << n2 << endl;

    return 0;
}