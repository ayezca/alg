#include <iostream>
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
    
    vector<State> states(n, State::notDefined);
    vector<int> pred(n, unknown);
    vector<int> dist(n, unknown);
    
    states[0] = State::inTree;
    dist[0] = 0;
    
    for (const auto& p: g[0])
    {
        pred[p.first] = 0;
        dist[p.first] = p.second;
    }
    
    int totalWeight = 0;
    
    for (int i = 1; i < n; ++i)
    {
        int minIndex = n;
        for (int j = 0; j < n; ++j)
        {
            if (states[j] != State::inTree && dist[j] != unknown && (minIndex == n || dist[j] < dist[minIndex]))
            {
                minIndex = j;
            }
        }

        if (minIndex == n)
        {
            cout << "Graph is not connected. It is imposible to build MST" << endl;
            return 1;
        }
        
        states[minIndex] = State::inTree;
        cout << char('a' + pred[minIndex]) << " " << char('a' + minIndex) << " " << dist[minIndex] << "\n";
        totalWeight += dist[minIndex];
        
        for (const auto& p : g[minIndex])
        {
            if (states[p.first] == State::notDefined)
            {
                states[p.first] = State::inBorder;
                pred[p.first] = minIndex;
                dist[p.first] = p.second;
            }
            else if (states[p.first] == State::inBorder && dist[p.first] > p.second)
            {
                pred[p.first] = minIndex;
                dist[p.first] = p.second;
            }
        }
        
    }
    
    cout << "Total weight: " << totalWeight << "\n";
}