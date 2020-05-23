#include <iostream>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

// const int white = 0;
// const int gray = 1;
// const int black = 2;

enum class Color {white, gray, black};

void dfs(const Graph& g, int u, vector<Color>& state, vector<int>& curComponent)
{
    state[u] = Color::gray;
    curComponent.push_back(u);
    for (auto v: g[u])
    {
        if (state[v] == Color::white)
        {
            dfs(g, v, state, curComponent);
        }
    }
    state[u] = Color::black;
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> g(n);
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char ch;
            cin >> ch;
            if (ch == '1')
            {
                g[i].push_back(j);
            }
        }
    }
    
    vector<Color> state(n, Color::white);
    
    int nComponents = 0;
    for (int i = 0; i < int(state.size()); ++i)
    {
        if (state[i] == Color::white)
        {
            vector<int> curComponent;
            dfs(g, i, state, curComponent);
            cout << ++nComponents << ":";
            for (auto v : curComponent)
            {
                cout << " " << v;
            }
            cout << endl;
        }
    }
    
   
}