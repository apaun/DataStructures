#include<iostream>
using namespace std;


void fun1(int& x)
{
    cout << "fun1 lvalue" << endl;
}

void fun1(int&& x)
{
    cout << "fun1 rvalue" << endl;
}

template<typename T> void Wrap(T&& x) // x is universal reference
{
    //fun1(x);
    fun1(forward<T>(x));
}

int main()
{
    int a = 10;
    //fun1(a);
    //fun1(19);
    Wrap(a);
    Wrap(20);

    return 0;
}