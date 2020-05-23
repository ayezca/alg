#include <bits/stdc++.h>

using namespace std;

int counter = 0;

int solve(int r, int c, const vector<vector<int>>& a)
{
    
    cout << r << ", " << c << ": " << ++counter << endl;
    
    if (r == 0 && c == 0)
    {
        return a[0][0];
    }
    
    if (r == 0)
    {
        return solve(r, c - 1, a) + a[r][c];
    }
    if (c == 0)
    {
        return solve(r - 1, c, a) + a[r][c];
    }
    
    return max(solve(r - 1, c, a), solve(r, c - 1, a)) + a[r][c]; 
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
    
    
    cout << solve(n - 1, m - 1, a) << "\n"; 
    
}