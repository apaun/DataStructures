#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
void printCombination(T set[], int setLength, int subSetLength, T subSet[], int setCurrIndex, int subSetCurrIndex)
{
    if(subSetLength == subSetCurrIndex)
    {
        for(int i = 0; i < subSetLength; i++)
        {
            cout << subSet[i] << " ";
        }
        cout << endl;
        return;
    }

    if(setCurrIndex >= setLength) return;
    subSet[subSetCurrIndex] = set[setCurrIndex];
    printCombination(set, setLength, subSetLength, subSet, setCurrIndex + 1, subSetCurrIndex + 1);


    while(setCurrIndex + 1 < setLength && set[setCurrIndex] == set[setCurrIndex + 1])
        setCurrIndex++;

    printCombination(set, setLength, subSetLength, subSet, setCurrIndex + 1, subSetCurrIndex);
} 


void permute(string a, int l, int r)
{
    if (l == r)
        cout << a << endl;
    else
    {
        for(int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
    
}

int main()
{
    int arr[] = {1, 2, 1, 3, 1};
    int setLength = sizeof(arr) / sizeof(arr[0]);
    int r = 3;
    int *subSet = new int[r];

    sort(arr, arr + setLength);

    printCombination<int>(arr, setLength, r, subSet, 0, 0);

    string someString = "abc";
    int stringLength = someString.length();
    char *abc = new char[stringLength];
    for(int i = 0; i < stringLength; i++)
    {
        abc[i] = someString[i];
    }
    char subSetString[r];

    sort(abc, abc + stringLength);
    printCombination<char>(abc, stringLength, 2, subSetString, 0, 0);

    cout << "Permute" << endl;
    permute(someString, 0, stringLength - 1);
    
    return 0;
}


