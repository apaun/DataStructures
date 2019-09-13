#include <iostream>

using namespace std;

bool isEven(char ch)
{
    return ch == '2' || ch == '4' || ch == '6' || ch == '8';
}

int main()
{
    
    string s = "574674546476";
    int len = 0;
    len = s.length();
    
    
    int memo[len + 1];
    
    for(int i = 0; i <= len; i++)
    {
        memo[i] = 0;
    }
    
    for(int i = len - 1; i >= 0; i--)
    {
        if(isEven(s[i]))
        {
            memo[i] = 1 + memo[i + 1];
        }
        else
        {
            memo[i] = memo[i + 1];
        }
        
    }
    
    for(int i = 0; i < len; i++)
    {
        cout << memo[i] << " ";
    }
    
    return 0;
}

