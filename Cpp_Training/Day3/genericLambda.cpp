#include <iostream>
#include <list>
#include <list>
#include<algorithm>

using namespace std;

int main()
{
    // lambda can use auto as parameter - This is known as generic lambda
    auto lm = [](auto &x) {
        cout << x << endl;
    };

    list<int> ls1 = {10, 20, 30, 40};
    list<float> ls2 = {11.1f, 22.2f, 33.3f, 44.4f};

    for_each(ls1.begin(), ls1.end(), lm);
    for_each(ls2.begin(), ls2.end(), lm);
    return 0;
}