// dynamic programming: bottom-up

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int64_t> table(n + 1);
    table[n] = 1;

    for (int i = n - 1; i > -1; --i)
    {
        if (i + 1 <= n)
        {
            table[i] += table[i + 1];
        }
        if (i + 2 <= n)
        {
            table[i] += table[i + 2];
        }
        if (i + 3 <= n)
        {
            table[i] += table[i + 3];
        }
    }

    cout << table[0] << "\n";
}