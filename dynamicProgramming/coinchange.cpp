#include <iostream>

using namespace std;

int coinChange(int coin[], int value, int coinLength)
{

    int result[coinLength + 1][value + 1];
    for (int i = 0; i <= coinLength; i++)
    {
        for (int j = 0; j <= value; j++)
        {
            if (i == 0 || j == 0)
            {
                result[i][j] = 0;
            }
            if (i == 1)
            {
                result[i][j] = j / coin[i - 1];
            }
            else if (coin[i - 1] > j)
            {
                result[i][j] = result[i - 1][j];
            }
            else
            {
                int temp1 = result[i - 1][j];
                int temp2 = 1 + result[i][j - coin[i - 1]];
                result[i][j] = temp1 < temp2 ? temp1 : temp2;
            }
        }
    }

    return result[coinLength][value];
}

int main()
{
    int coin[] = {1, 2, 3};
    int value = 6;
    std::cout << coinChange(coin, value, 3);
    return 0;
}