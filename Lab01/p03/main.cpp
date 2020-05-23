// g++ -std=c++17 main.cpp ListInt.cpp

#include <iostream>

#include "ListInt.h"


using namespace std;

void printInDirectOrder(ListInt& lst)
{
    for (auto e: lst)
    {
        cout << e << " ";
    }
    cout << "\n";
}

void printInReversedOrder(ListInt& lst)
{
    for (auto p = lst.rbegin(); p != lst.rend(); ++p)
    {
        cout << *p << " ";
    }
    cout << "\n";
}

int main()
{
    ListInt lst;
    cout << sizeof(lst) << endl;
    
    for (int x; cin >> x;)
    {
        lst.pushBack(x);
    }    
    
    printInDirectOrder(lst);
    printInReversedOrder(lst);
    
    
    for (auto p = lst.begin(); p != lst.end(); ++p)
    {
        if (*p % 2 == 0)
        {
            p = lst.insert(p, 0);
            ++p;
        }
    }
    
    printInDirectOrder(lst);
    printInReversedOrder(lst);
    
    for (auto p = lst.begin(); p != lst.end();)
    {
        if (*p % 2 == 0)
        {
            p = lst.erase(p);
            
        }
        else
        {
            ++p;
        }
    }
    
    printInDirectOrder(lst);
    printInReversedOrder(lst);
}
