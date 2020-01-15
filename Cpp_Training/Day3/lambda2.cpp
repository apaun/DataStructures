#include <iostream>

using namespace std;

int main()
{
    int x = 10, y = 20;

    /*
    auto lm1 = [] ()
    {
        cout << "inside lambda, x :" << x << ", y" << y << endl;
    };
    */

    auto lm1 = [&]() {
        x = 100;
        y = 200;
        cout << "inside lambda, x :" << x << ", y" << y << endl;
    };

    lm1();

    cout << x << y << endl;

    return 0;
}