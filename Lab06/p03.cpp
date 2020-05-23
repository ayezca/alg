#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <map>


using namespace std;

enum class Color {white, red, black};

int main()
{
    int nEdges;
    cin >> nEdges;
    
    map<string, vector<string>> g;
    for (int i = 0; i < nEdges; ++i)
    {
        string u;
        cin >> u;
        string w;
        cin >> w;
        g[u].push_back(w);
        g[w].push_back(u);
    }
    string source;
    cin >> source;
    string dest;
    cin >> dest;
    
    map<string, int> dist;
    map<string, string> pred;
    map<string, Color> state;
    
    for (const auto& p: g)
    {
        state[p.first] = Color::white;
    }
    
    queue<string> q;
    
    q.push(source);
    dist[source] = 0;
    pred[source] = "";
    
    while (!q.empty())
    {
        string u = q.front();

        q.pop();
        state[u] = Color::black;
        
        for (const auto& v : g[u])
        {
            if (state[v] == Color::white)
            {
                state[v] = Color::red;
                q.push(v);
                dist[v] = dist[u] + 1;
                pred[v] = u;
            }
        }
    }
    
    for (const auto& p : dist)
    {
        cout << p.first << ": " << p.second << endl;
    }
        
    vector<string> trip;
    trip.push_back(dest);
    while (pred[trip.back()] != "")
    {
        trip.push_back(pred[trip.back()]);
    }
    
    reverse(trip.begin(), trip.end());
    
    for (const auto& e : trip)
    {
        cout << " " << e;
    }
    cout << endl;
    
}