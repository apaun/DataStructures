#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class CA
{

private:
    int a, b;

public:
    CA(int x = 0, int y = 0) : a(x), b(y) {}

    void print() const { cout << a << " " << b << endl; }
    int sum() { return a + b; }
};

int main()
{
    list<CA> ls1;

    for (int i = 0; i < 5; i++)
    {
        ls1.push_back(CA(i, i + 20));
    }

    int total{}; // int total = 0;
    auto lm = [&total](CA &obj) {
        obj.print();
        total += obj.sum();
    };

    for_each(ls1.begin(), ls1.end(), lm);

    cout << total << endl;

    return 0;
}