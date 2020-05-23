#include <bits/stdc++.h>

using namespace std;

int counter = 0;

int solve(int r, int c, const vector<vector<int>>& a, vector<vector<int>>& t)
{
    
    cout << r << ", " << c << ": " << ++counter << endl;
    
    if (t[r][c] != -1)
    {
        return t[r][c];
    }
    
    if (r == 0)
    {
        return t[r][c] = solve(r, c - 1, a, t) + a[r][c];
    }
    if (c == 0)
    {
        return t[r][c] = solve(r - 1, c, a, t) + a[r][c];
    }
    
    return t[r][c] = max(solve(r - 1, c, a, t), solve(r, c - 1, a, t)) + a[r][c]; 
}

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
    cout << solve(n - 1, m - 1, a, t) << "\n"; 
    
}