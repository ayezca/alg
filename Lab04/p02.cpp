// 3! = 3 * 2 * 1
// 0! = 1

// n == 0: n! = 1
// n > 0 : n! = n * (n - 1)!

#include <iostream>
#include <cstdint>

using namespace std;

int64_t factorial(int n)
{
    return (n == 0) ? 1 : n * factorial(n - 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n << "! = " << factorial(n) << endl;
    }
}