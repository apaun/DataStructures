#include<iostream>

using namespace std;

int max(int n, int m)
{
    return n > m ? n : m;
}

int knapSackRecursive(const int *v, const int *w, int n, int weight)
{
    int result = 0;
    if(n == 0 || weight == 0)
        result = 0;
    else if(w[n - 1] > weight)
        result = knapSackRecursive(v, w, n -1, weight);
    else
        result = max(knapSackRecursive(v, w, n -1, weight) , v[n - 1] + knapSackRecursive(v, w, n - 1, weight - w[n - 1]));

    return result;
}

int knapSackBottomUp(const int *v, const int *w, int n, int weight)
{
    int knapSackMemo[n + 1][weight + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight; j++)
        {
            if (i == 0 || j == 0)
                knapSackMemo[i][j] = 0;
            else if(w[i - 1] <= j)
            {
                int tmp1 = knapSackMemo[i - 1][j];
                int tmp2 = v[i - 1] + knapSackMemo[i - 1][j - w[i - 1]];
                knapSackMemo[i][j] = max(tmp1, tmp2);
            }
            else
                knapSackMemo[i][j] = knapSackMemo[i - 1][weight];
        }
    }

    return knapSackMemo[n][weight];
}



int main()
{
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 

    int n = sizeof(val)/sizeof(val[0]); 

    cout << "0-1 Knapsack recursive is " << knapSackRecursive(val, wt, n, W) << endl;
    cout << "0-1 Bottom Up is " << knapSackBottomUp(val, wt, n, W) << endl;

    return 0; 
}