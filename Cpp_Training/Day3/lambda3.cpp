#include <iostream>

using namespace std;

int main()
{
    int x= 10, y = 20;

    // auto lm1 = [=] ()
    // {
    //     x = 100; // THis will not work, since its only readonly
    //     y = 200;
    //     cout << "inside lambda, x :" << x << ", y" << y << endl;
    // };

    auto lm1 = [=] () mutable
    {
        x += 100;
        y += 200;
        cout << "inside lambda, x :" << x << ", y" << y << endl;
        // mutalble -  x and y has its own value over here and wont get affected outside lambda
        // values will be retained between lambda calls - statefull lambda
    };

    lm1();
    lm1();
    lm1();

    cout << x << y << endl;

    

    return 0;
}