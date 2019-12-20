#include<iostream>
#include<vector>

using namespace std;
const unsigned int M = 1000000007;


int main()
{
    int *p;
    int var = 10;
    p = &var;
    p[1] = 67;
    cout << p[0] << endl;
    cout << p[1] << endl;

    int *arr;
    arr = new int[5];
    arr[0] = 10;
    arr[1] = 20;
    p = arr;
    // delete(arr);

    cout << p[0] << endl;
    cout << p[1] << endl;

    vector<int> *adj;
    vector<int> abc;
    abc.push_back(10);
    abc.push_back(50);

    adj = &abc;

    for(auto i : *adj)
    {
        cout << i << endl;
    }


    vector<int> *adjMatrix;
    adjMatrix = new vector<int>[5];
    adjMatrix[0].push_back(1);
    adjMatrix[0].push_back(2);
    adjMatrix[1].push_back(10);
    adjMatrix[1].push_back(20);

    for(auto i : adjMatrix[0])
    {
        cout << i << endl;
    }

    for(auto i : adjMatrix[1])
    {
        cout << i << endl;
    }



    return 0;
}