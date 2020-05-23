#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    map<string, set<int>> m;

    int nLines = 0;
    for (string line; getline(cin, line);)
    {
        ++nLines;
        istringstream sinp(line);
        for (string w; sinp >> w;)
        {
            m[w].insert(nLines);
        }
    }
    
    for (const auto& p : m)
    {
        cout << p.first << ":";
        for (const auto i: p.second)
        {
            cout << " " << i;
        }
        cout << "\n";
    }
}

