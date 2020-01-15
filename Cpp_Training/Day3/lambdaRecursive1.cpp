#include <iostream>
#include <functional>

using namespace std;

int main()
{
    // when we want lambda to recursive, add fib handle in capture []
    function<int(int)> fib = [&fib](int x)
    {
        return x <= 2 ? 1 : fib(x - 1) + fib(x - 2);
    };
    
    cout << fib(20) << endl;;
    return 0;
}