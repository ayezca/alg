#include <bits/stdc++.h>

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    int n; cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    
    vector<int> d(n, 1);
    vector<int> p(n, -1);
    
    int maxIndex = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j > -1; --j)
        {
            if (v[i] > v[j] && d[j] + 1 > d[i])
            {
                d[i] = d[j] + 1;
                p[i] = j;
                if (d[i] > d[maxIndex])
                {
                    maxIndex = i;
                }
            }
        }
    }
    
    vector<int> r;
    r.push_back(maxIndex);
    while (p[r.back()] != -1)
    {
        r.push_back(p[r.back()]);
    }
    
    reverse(begin(r), end(r));
    
    for (int i: r)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}