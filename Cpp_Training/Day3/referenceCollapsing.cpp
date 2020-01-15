#include<iostream>
using namespace std;

// template<typename T> void Wrapper(T& x, T& y)
// {
//     cout << x << " " << y << endl;
// }

// template<typename T> void Wrapper(const T& x, const T& y)
// {
//     cout << x << " " << y << endl;
// }


// an universal reference type can act as an alias to both
// RVALUE as well as LVALUE
template<typename T1, typename T2> void Wrapper(T1&& x, T2&& y)
{
    cout << x << " " << y << endl;
}


int main()
{
    int a = 10; // 
    int b = 20;

    Wrapper(a, b); // Wrapper(int&, int&)
    Wrapper(100, 200); //Wrapper(int&& , int&&)
    Wrapper(a, 200);

    return 0;

}