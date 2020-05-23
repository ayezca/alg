#include <iostream>

#include "MapStrInt.h"

using namespace std;

int& MapStrInt::operator[](const string& k)
{
    Node* pred = nullptr;
    Node* curr = root;
    bool isLeft = false;
    while (curr != nullptr)
    {
        pred = curr;
        if (k < curr->data.first)
        {
            isLeft = true;
            curr = curr->left;
        }
        else if (curr->data.first < k)
        {
            isLeft = false;
            curr = curr->right;
        }
        else
        {
            return curr->data.second;
        }
    }

    Node* t = new Node(k, 0, nullptr, nullptr);
    
    ++length;
    
    if (root == nullptr)
    {
        root = t;
    }
    else if (isLeft)
    {
        pred->left = t;
    }
    else
    {
        pred->right = t;
    }
    
    return t->data.second;
}


void MapStrInt::printInOrder(Node* r) const
{
    if (r)
    {
        printInOrder(r->left);
        cout << r->data.first << ": " << r->data.second << endl;
        printInOrder(r->right);
    }
}

void MapStrInt::clear(Node* r)
{
    if (r)
    {
        clear(r->left);
        clear(r->right);
        delete r;
    }
}
