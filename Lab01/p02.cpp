#include <iostream>
#include <list>


using namespace std;

void printInDirectOrder(const list<int>& lst)
{
    for (auto e: lst)
    {
        cout << e << " ";
    }
    cout << "\n";
}

void printInReversedOrder(const list<int>& lst)
{
    // const_reverse_iterator p = lst.rbegin();
    for (auto p = lst.rbegin(); p != lst.rend(); ++p)
    {
        cout << *p << " ";
    }
    cout << "\n";
}

int main()
{
    list<int> lst;
    cout << sizeof(lst) << endl;
    
    for (int x; cin >> x;)
    {
        lst.push_back(x);
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
