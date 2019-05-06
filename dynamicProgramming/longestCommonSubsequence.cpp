#include<iostream>
#include<string.h>

using namespace std;

int LcsMemo[100][100];

int max(int n, int m)
{
    return n > m ? n : m;
}

int LcsRecursive(const char* p, const char* q, int lenP, int lenQ)
{
    if(lenP == 0 || lenQ == 0)
        return 0;
    else if(p[lenP - 1] == q[lenQ - 1])
       return 1 + LcsRecursive(p, q,lenP - 1, lenQ - 1);
    else
        return max(LcsRecursive(p, q,lenP - 1, lenQ), LcsRecursive(p, q,lenP, lenQ - 1));
}

int LcsMemoization(const char* p, const char* q, int lenP, int lenQ)
{
    if(LcsMemo[lenP][lenQ] != -1)
        return LcsMemo[lenP][lenQ];

    int result;
    if(lenP == 0 || lenQ == 0)
        result = 0;
    else if(p[lenP - 1] == q[lenQ - 1])
        result = 1 + LcsRecursive(p, q,lenP - 1, lenQ - 1);
    else
        result = max(LcsRecursive(p, q,lenP - 1, lenQ), LcsRecursive(p, q,lenP, lenQ - 1));
    
    LcsMemo[lenP][lenQ] = result;
    return result;

}

int LcsBottomUp(const char* p, const char* q, int lenP, int lenQ)
{
    int LcsMemo[100][100];

    for(int i = 0; i <= lenP; i++)
    {
        for(int j = 0; j <= lenQ; j++)
        {
            if (i == 0 || j == 0)
                LcsMemo[i][j] = 0;
            else if (p[i] == q[j])
                LcsMemo[i][j] = 1 + LcsMemo[i - 1][j - 1];
            else
                LcsMemo[i][j] = max(LcsMemo[i - 1][j], LcsMemo[i][j - 1]);
        }   
    }

    return LcsMemo[lenP][lenQ];

}


int main()
{
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 


    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            LcsMemo[i][j] = -1;
        }
    }
  
    cout << "LCS is " << LcsRecursive(X, Y, m, n) << endl;
    cout << "LCS Memo is " << LcsMemoization(X, Y, m, n) << endl;
    cout << "LCS Bottom Up is " << LcsBottomUp(X, Y, m, n) << endl;


    return 0;

}