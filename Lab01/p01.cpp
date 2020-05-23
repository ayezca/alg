#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int aData, Node* aPrev, Node* aNext)
        : data(aData)
        , prev(aPrev)
        , next(aNext)
    {
    }
};

using namespace std;

void pushBack(Node*& head, Node*& tail, int value)
{
    if (head == nullptr)
    {
        head = tail = new Node(value, nullptr, nullptr);
    }
    else
    {
        tail->next = new Node(value, tail, nullptr);
        tail = tail->next;
    }
}

void printInDirectOrder(Node* head)
{
    for (Node* p = head; p != nullptr; p = p->next)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

void printInReversedOrder(Node* tail)
{
    for (Node* p = tail; p != nullptr; p = p->prev)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

void insertBefore(Node*& head, Node* p, int value)
{
    if (p == head)
    {
        head = head->prev = new Node(value, nullptr, p);
    }
    else
    {
        p->prev = p->prev->next = new Node(value, p->prev, p);
    }
}

Node* erase(Node*& head, Node*& tail, Node* p)
{
    if (head == tail)
    {
        delete head;
        return head = tail = nullptr;
    }

    if (p == head)
    {
        head = head->next;
        head->prev =  nullptr;
        delete p;
        return head;
    }

    if (p == tail)
    {
        tail = tail->prev;
        tail->next = nullptr;
        delete p;
        return nullptr;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    Node* r = p->next;
    delete p;

    return r;
}


void clear(Node*& head, Node*& tail)
{
    while (head)
    {
        Node* t = head;
        head = head->next;
        delete t;
    }
    tail = nullptr;
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int x; cin >> x;)
    {
        pushBack(head, tail, x);
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);


    for (Node* p = head; p; p = p->next)
    {
        if (p->data % 2 == 0)
        {
            insertBefore(head, p, 0);
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    for (Node* p = head; p;)
    {
        if (p->data % 2 == 0)
        {
            p = erase(head, tail, p);
        }
        else
        {
            p = p->next;
        }
    }

    printInDirectOrder(head);
    printInReversedOrder(tail);

    clear(head, tail);

    printInDirectOrder(head);
    printInReversedOrder(tail);
}