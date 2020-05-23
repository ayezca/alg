#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    vector<vector<int>> a(n, vector<int>(m));
    
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            cin >> a[r][c];
        }
    }
    
    
    vector<vector<int>> t(n, vector<int>(m, -1));
    t[0][0] = a[0][0];
    for (int c = 1; c < m; ++c)
    {
        t[0][c] = t[0][c - 1] + a[0][c];
    }
    for (int r = 1; r < n; ++r)
    {
        t[r][0] = t[r - 1][0] + a[r][0];
    }
    
    for (int r = 1; r < n; ++r)
    {
        for (int c = 1; c < m; ++c)
        {
            t[r][c] = max(t[r - 1][c], t[r][c - 1]) + a[r][c];
        }
    }
    cout << t[n - 1][m - 1] << "\n"; 
}