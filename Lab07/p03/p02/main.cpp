// g++ -std=c++17 main.cpp

#include <algorithm>
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
    int u;
    int v;
    int w;
    while (cin >> u >> v >> w && !(u == 0 && v == 0 && w == 0))
    {
        g[u - 1].emplace_back(v - 1, w);
    }
    int s;
    cin >> s;
    --s;

    int d;
    cin >> d;
    --d;

    set<pair<int, int>> borderDist;
    vector<set<pair<int, int>>::iterator> borderLoc(n);

    vector<State> states(n, State::notDefined);
    vector<int> pred(n, unknown);
    vector<int> dist(n, unknown);

    borderLoc[s] = borderDist.emplace(0, s).first;
    dist[s] = 0;
    states[s] = State::inBorder;

    while (!borderDist.empty())
    {
        auto [d, u] = *begin(borderDist);
        borderDist.erase(begin(borderDist));
        states[u] = State::inTree;

        for (auto [v, w] : g[u])
        {
            if (states[v] == State::notDefined)
            {
                pred[v] = u;
                dist[v] = d + w;
                borderLoc[v] = borderDist.emplace(dist[v], v).first;
                states[v] = State::inBorder;
            }
            else if (states[v] == State::inBorder && dist[v] > d + w)
            {
                pred[v] = u;
                dist[v] = d + w;
                borderDist.erase(borderLoc[v]);
                borderLoc[v] = borderDist.emplace(dist[v], v).first;
            }
        }
    }

    if (states[d] == State::notDefined)
    {
        cout << "impossible\n";
    }
    else
    {
        vector<int> path = {d};
        while (path.back() != s)
        {
            path.push_back(pred[path.back()]);
        }

        cout << "shortest path:";
        for (auto i = rbegin(path); i != rend(path); ++i)
        {
            cout << " " << *i + 1;
        }
        cout << "\n";
    }
}