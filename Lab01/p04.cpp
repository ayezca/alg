#include <chrono>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <random>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

void expWithVector(int n)
{
    mt19937 rndGen;
    uniform_int_distribution<int> numDist(0, numeric_limits<int>::max());

    vector<int> lst;
    for (int i = 0; i < n; ++i)
    {
        int x = numDist(rndGen);
        auto p = begin(lst);
        while (p != end(lst) && *p <= x)
        {
            ++p;
        }
        lst.insert(p, x);
    }
}


void expWithList(int n)
{
    mt19937 rndGen;
    uniform_int_distribution<int> numDist(0, numeric_limits<int>::max());

    list<int> lst;
    for (int i = 0; i < n; ++i)
    {
        int x = numDist(rndGen);
        auto p = begin(lst);
        while (p != end(lst) && *p <= x)
        {
            ++p;
        }
        lst.insert(p, x);
    }
}

void printTime(const string& msg, void exp(int), int n)
{
    cout << msg << "\n"
         << string(80, '-') << "\n";

    auto tBeg = high_resolution_clock::now();
    exp(n);
    auto tEnd = high_resolution_clock::now();

    cout << "time in ms: " << duration_cast<milliseconds>(tEnd - tBeg).count() << "\n"
         << string(80, '-') << "\n";
}

int main()
{
    const int n = 50000;
    printTime("vector with size " + to_string(n), expWithVector, n);
    printTime("list with size " + to_string(n), expWithList, n);

}