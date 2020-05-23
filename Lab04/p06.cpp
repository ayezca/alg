// 1 1 2 3 5 8 13 21 ...

#include <iostream>
#include <cstdint>

using namespace std;

// exponential growth
int64_t fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    return fib(n - 2) + fib(n - 1);
}

// O(n)
int64_t fibIter(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    
    int64_t a = 1;
    int64_t b = 1;
    for (int i = 2; i <= n; ++i)
    {
        int64_t t = a + b;
        a = b;
        b = t;
    }
    
    return b;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << "Fib(" << n << ") = " << fibIter(n) << endl;
    }
}