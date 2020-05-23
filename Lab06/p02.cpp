#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

enum class Color {white, gray, black};

using Graph = vector<vector<int>>;

void dfs(const Graph& g, int u, vector<Color>& state, deque<int>& r)
{
    state[u] = Color::gray;
    
    for (auto v : g[u])
    {
        if (state[v] == Color::gray)
        {
            throw runtime_error("loop");
        }
        if (state[v] == Color::white)
        {
            dfs(g, v, state, r);
        }
    }
    
    state[u] = Color::black;
    
    r.push_front(u);
}

int main()
{

    int n;
    cin >> n >> ws;
    
    
    Graph g(n);
    int row = 0;
    for (string line; getline(cin, line); ++row)
    {
        if (line != "-")
        {
            istringstream sinp(line);
            int v;
            while (sinp >> v)
            {
                 g[row].push_back(v - 1);   
            }
        }
    }
    
    vector<Color> state(n, Color::white);
    
    deque<int> r;
    for (int i = 0; i < n; ++i)
    {
        if (state[i] == Color::white)
        {
            dfs(g, i, state, r);
        }
    }
    
    cout << "result:";
    for (auto e : r)
    {
        cout << " " << e + 1;
    }
    cout << endl;
}