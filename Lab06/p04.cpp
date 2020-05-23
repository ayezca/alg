#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum class Color {white, red, black};
const int nil = -1;

bool inRange(int r, int c, int n)
{
    return 0 <= r && r < n && 0 <= c && c < n;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    int source = -1;
    int dest = -1;

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            cin >> g[r][c];
            if (g[r][c] == 'S')
            {
                source = n * r + c;
            }
            else if (g[r][c] == 'D')
            {
                dest = n * r + c;
            }
        }
    }
   
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    vector<int> pred(n * n, nil);
    vector<Color> state(n * n, Color::white);

    queue<int> q;
    q.push(source);
    state[source] = Color::red;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        state[u] = Color::black;

        int r = u / n;
        int c = u % n;
        for (int i = 0; i < 4; ++i)
        {

            int tr = r + dr[i];
            int tc = c + dc[i];
            int v = tr * n + tc;
            if (inRange(tr, tc, n) && g[tr][tc] != '#' && state[v] == Color::white)
            {
                q.push(v);
                state[v] = Color::red;
                pred[v] = u;
                if (v == dest)
                {
                    goto labForWhile;
                }
            }
        }
    }

labForWhile:
    if (state[dest] == Color::white)
    {
        cout << "Unreachable" << endl;
    }
    else
    {
        int length = 0;
        int curr = dest;
        while (g[curr / n][curr % n] != 'S')
        {
            g[curr / n][curr % n] = '*';
            ++length;
            curr = pred[curr];
        }
        for (const auto& r : g)
        {
            for (const auto& c : r)
            {
                cout << c;
            }
            cout << endl;
        }
        cout << "dist: " << length << endl;
    }
}