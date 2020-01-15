#include <iostream>

using namespace std;

class CA
{
public:
    CA() { cout << "CA default constructor" << endl; }
    CA(int x) { cout << "CA one arg cotr" << endl; }
    CA(int x, int y) { cout << "CA two arg cotr" << endl; }
};

class CB : public CA
{
public:
    using CA::CA;
    CB(int x) { cout << "CB one arg cotr" << endl; }
    // CB():CA() {} =>complier create a default constructor
    // CB(int x) { cout << "CB one arg cotr" << endl; }
};

int main()
{
    CB obj1;
    CB obj2(100);
    CB obj3(100, 200);
    return 0;
}