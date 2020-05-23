// g++ -std=c++17 main.cpp

#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

enum class State {inBorder, inTree, notDefined};
const int unknown = -1;

int main()
{
    int n;
    cin >> n;
    
    vector<vector<pair<int, int>>> g(n);
    char u;
    char v;
    int w;
    while (cin >> u >> v >> w)
    {
        g[u - 'a'].emplace_back(v - 'a', w);
        g[v - 'a'].emplace_back(u - 'a', w);
    }
    
    set<pair<int, int>> borderDist;
    vector<set<pair<int, int>>::iterator> borderLoc(n);
    vector<int> pred(n, unknown);
    vector<int> dist(n, unknown);
    vector<State> states(n, State::notDefined);
    
    states[0] = State::inTree;
    
    for (auto [v, w]: g[0])
    {
        pred[v] = 0;
        dist[v] = w;
        states[v] = State::inBorder;
        borderLoc[v] = borderDist.emplace(w, v).first;
    }
    
    int totalWeight = 0;
    
    for (int i = 1; i < n; ++i)
    {
        if (borderDist.empty())
        {
            cout << "The graph is not connected. It is imposible to build a MST" << endl;
            return 1;
        }
        
        auto [d, u] = *begin(borderDist);
        borderDist.erase(begin(borderDist));
        states[u] = State::inTree;
        
        cout << char('a' + pred[u]) << " " << char('a' + u) << " " << d << "\n";
        totalWeight += d;
        
        for (auto [v, w] : g[u])
        {
            if (states[v] == State::notDefined)
            {
                states[v] = State::inBorder;
                pred[v] = u;
                dist[v] = w;
                borderLoc[v] = borderDist.emplace(w, v).first;
            }
            else if (states[v] == State::inBorder && dist[v] > w)
            {
                pred[v] = u;
                dist[v] = w;
                borderDist.erase(borderLoc[v]);
                borderLoc[v] = borderDist.emplace(w, v).first;
            }
        }
    }
    
    cout << "Total weight: " << totalWeight << "\n";
}