#include <ioste>
const unsigned int M = 1000000007;

int main()
{
    long long t;
    std::cin >> t;
    while (t--)
    {
        long long result = 0;
        long long n;
        std::cin >> n;

        for (int i = 1; i <= n; i++)
        {
            result = (result + i + (result * i)) % M;
        }

        std::cout << result << std::endl;
    }
    return 0;
}