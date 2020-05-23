#include "ListInt.h"

using namespace std;

#ifdef AU_DEBUG
int ListInt::deleteCount = 0;
#endif


ListInt::ListInt(const ListInt& other)
    : head(new Node(0, nullptr, nullptr))
    , tail(new Node(0, head, nullptr))
    , sz(0)
{
    head->next = tail;
    for (Node* p = other.head->next; p != other.tail; p = p->next)
    {
        pushBack(p->data);
    }
}

ListInt& ListInt::operator=(const ListInt& other)
{
    if (this != &other)
    {
        ListInt t = other;
        swap(t);
    }
    return *this;
}

ListInt::~ListInt()
{
#ifdef AU_DEBUG
    deleteCount = 0;
#endif
    for (Node* p = head; p;)
    {
        Node* t = p;
        p = p->next;
        delete t;
#ifdef AU_DEBUG
       ++deleteCount;
#endif       
    }
}

string ListInt::toStr() const
{
    string res = "{";
    bool isFirst = true;
    for (Node* p = head->next; p != tail; p = p->next)
    {
        res += isFirst ? " ": ", ";
        res += to_string(p->data) ;
        isFirst = false;
    }
    res += "}";

    return res;
}
