// divide and conquer

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

int64_t solve(int m, int n)
{
    cout << "solve(" << m << ", " << n << "): " << ++counter << endl;
    
    if (m == n)
    {
        return 1;
    }
    
    int64_t r = 0;
    if (m + 1 <= n)
    {
        r += solve(m + 1, n);
    }
    if (m + 2 <= n)
    {
        r += solve(m + 2, n);
    }
    if (m + 3 <= n)
    {
        r += solve(m + 3, n);
    }

    return r;
}

int main()
{
    int n;
    cin >> n;
    
    cout << solve(0, n) << "\n";
}