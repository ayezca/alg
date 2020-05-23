#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Point
{
    int x;
    int y;
    Point(int aX, int aY)
        : x(aX)
        , y(aY)
    {
    }
};

// functor = functional object

struct CmpPoint
{
    bool operator()(const Point& a, const Point& b) const
    {
        if (a.x < b.x) return true;
        if (a.x > b.x) return false;
        return a.y < b.y;
    }
};

using MapOfCaches = map<Point, vector<string>, CmpPoint>;

void insertCache(MapOfCaches& caches)
{
    string line;

    getline(cin, line);
    int x = stoi(line);

    getline(cin, line);
    int y = stoi(line);

    getline(cin, line);
    istringstream sinp(line);

    string item;
    while (sinp >> item)
    {
        caches[ {x, y}].push_back(item);
    }
}

void checkCache(const MapOfCaches& caches)
{
    string line;

    getline(cin, line);
    int x = stoi(line);

    getline(cin, line);
    int y = stoi(line);

    auto it = caches.find({x, y});

    if (it != caches.end())
    {
        for (const auto& e : it->second)
        {
            cout << " " << e;
        }
        cout << "\n";
    }
    else
    {
        cout << "Cache does not exist\n";
    }
}

void eraseCache(MapOfCaches& caches)
{
    string line;

    getline(cin, line);
    int x = stoi(line);

    getline(cin, line);
    int y = stoi(line);

    cout << (caches.erase({x, y}) ? "OK" : "No such cache") << endl;
}

void printCaches(const MapOfCaches& caches)
{
    for (const auto& p : caches)
    {
        cout << "{" << p.first.x << ", " < p.first.y << "}:";
        for (const auto& item : p.second)
        {
            cout << " " << item;
        }
        cout << "\n";
    }
}

int main()
{
    MapOfCaches caches;

    string cmd;
    while (getline(cin, cmd))
    {
        if (cmd == "insert")
        {
            insertCache(caches);
        }
        else if (cmd == "check")
        {
            checkCache(caches);
        }
        else if (cmd == "erase")
        {
            eraseCache(caches);
        }
        else if (cmd == "print")
        {
            printCaches(caches);
        }
        else
        {
            cout << "Unknown command" << endl;
        }
    }
}



