#include <iostream>
#include <functional>

using namespace std;

// This wont work, we need to enclose this under a fuction or another lambda
// Issue is with passing &fib in [], since capture can only work with outer scope
// and since this is global lambda, it has nothing to capture
// function<int(int)> fib = [&fib](int x)
// {
//     return x <= 2 ? 1 : fib(x - 1) + fib(x - 2);
// };

auto rFib = [](int x)
{
    function<int(int)> fib = [&fib](int x)
    {
        return x <= 2 ? 1 : fib(x - 1) + fib(x - 2);
    };

    return fib(x);
};

int main()
{   
    cout << rFib(20) << endl;;
    return 0;
}