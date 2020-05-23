// dynamic programming: top-down

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

// divide-and-conquer: O(k1^(k2*n))
// dynamic programming (memoization): T(n) = k1 * n + c1:  O(N)

int64_t solve(int m, int n, vector<int64_t>& table)
{
    cout << "solve(" << m << ", " << n << "): " << ++counter << endl;
    
    if (table[m] != 0)
    {
        return table[m];
    }
    
    int64_t r = 0;
    if (m + 1 <= n)
    {
        r += solve(m + 1, n, table);
    }
    if (m + 2 <= n)
    {
        r += solve(m + 2, n, table);
    }
    if (m + 3 <= n)
    {
        r += solve(m + 3, n, table);
    }

    return table[m] = r;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int64_t> table(n + 1);
    table[n] = 1;
    
    cout << solve(0, n, table) << "\n";
}