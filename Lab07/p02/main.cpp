#include <algorithm>
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

    vector<State> states(n, State::notDefined);
    vector<int> pred(n, unknown);
    vector<int> dist(n, unknown);

    states[s] = State::inBorder;
    dist[s] = 0;

    for (int i = 0; i < n; ++i)
    {
        int minIndex = n;
        for (int j = 0; j < n; ++j)
        {
            if (states[j] != State::inTree && dist[j] != unknown && (minIndex == n || dist[j] < dist[minIndex]))
            {
                minIndex = j;
            }
        }

        if (minIndex == n) break;

        states[minIndex] = State::inTree;

        for (const auto& p : g[minIndex])
        {
            if (states[p.first] == State::notDefined)
            {
                states[p.first] = State::inBorder;
                pred[p.first] = minIndex;
                dist[p.first] = dist[minIndex] + p.second;
            }
            else if (states[p.first] == State::inBorder && dist[p.first] > dist[minIndex] + p.second)
            {
                pred[p.first] = minIndex;
                dist[p.first] = dist[minIndex] + p.second;
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

        reverse(path.begin(), path.end());

        cout << "shortest path:";
        for (auto e : path)
        {
            cout << " " << e + 1;
        }
        cout << "\n";
    }
}