#include <iostream>

using namespace std;

// 1 2 3 4 5 6 7 8 9
// x = 1
// 9 8 7 6 5 4 3 2 1
// 3 1 2
// 2 1 3

void readAndPrintInReversedOrder()
{
    int x;
    if (cin >> x)
    {
        readAndPrintInReversedOrder();
        cout << " " << x;
    }
}

int main()
{
    readAndPrintInReversedOrder();

    vector<int> v;
    for (int x; cin >> x;)
    {
        v.push_back(x);
    }

    for (int i = int(v.size()) - 1; i > -1; --i)
    {
        cout << " " << v[i];
    }
}