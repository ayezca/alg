#include "BSTreeInt.h"

using namespace std;

bool BSTreeInt::insert(int k)
{
#ifdef AUCA_DEBUG
    path = "";
#endif
    if (root == nullptr)
    {
        root = new Node(k, nullptr, nullptr);
        ++sz;
        return true;
    }
    
    bool isLeft = true;
    Node* prev = nullptr;
    Node* curr = root;
    while (curr != nullptr)
    {
        if (k > curr->data)
        {
#ifdef AUCA_DEBUG
            path += "R";
#endif

            isLeft = false;
            prev = curr;
            curr = curr->rgt;
        }
        else if (k < curr->data)
        {
#ifdef AUCA_DEBUG
            path += "L";
#endif

            isLeft = true;
            prev = curr;
            curr = curr->lft;
        }
        else
        {
            return false;
        }
    }
    
    if (isLeft)
    {
        prev->lft = new Node(k, nullptr, nullptr);
    }
    else
    {
        prev->rgt = new Node(k, nullptr, nullptr);
    }
    ++sz;
    
    return true;
}

bool BSTreeInt::find(int k) const
{
#ifdef AUCA_DEBUG
    path = "";
#endif
    Node* curr = root;
    while (curr)
    {
        if (k < curr->data)
        {
#ifdef AUCA_DEBUG
            path += "L";
#endif
            curr = curr->lft;
        }
        else if (curr->data < k)
        {
#ifdef AUCA_DEBUG
            path += "R";
#endif
            curr = curr->rgt;
        }
        else
        {
            return true;
        }
    }
    
    return false;
}

bool BSTreeInt::erase(int k)
{
    bool isLeft = true;
    Node* prev = nullptr;
    Node* curr = root;
    while (curr)
    {
        if (k < curr->data)
        {
            isLeft = true;
            prev = curr;
            curr = curr->lft;
        }
        else if (curr->data < k)
        {
            isLeft = false;
            prev = curr;
            curr = curr->rgt;
        }
        else
        {
            break;
        }
    }
    
    if (curr == nullptr)
    {
        return false;
    }
    
    if (curr->lft == nullptr && curr->rgt == nullptr)
    {
        eraseLeaf(curr, prev, isLeft);        
    }
    else if (curr->lft && curr->rgt)
    {
        eraseNodeWithTwoChildren(curr, prev, isLeft);
    }
    else 
    {
        eraseNodeWithOneChild(curr, prev, isLeft);
    }
    
    return true;
}

void BSTreeInt::eraseLeaf(Node* curr, Node* prev, bool isLeft)
{
    if (curr == root)
    {
        delete root;
        root = nullptr;
    }    
    else if (isLeft)
    {
        prev->lft = nullptr;
        delete curr;
    }
    else
    {
        prev->rgt = nullptr;
        delete curr;
    }
    --sz;
}

void BSTreeInt::eraseNodeWithOneChild(Node* curr, Node* prev, bool isLeft)
{
    if (curr == root)
    {
        if (curr->lft)
        {
            root = root->lft; 
        }
        else
        {
            root = root->rgt;
        }
    }
    else
    {
        if (isLeft)
        {
            prev->lft = curr->lft ? curr->lft : curr->rgt;
        }
        else
        {
            prev->rgt = curr->lft ? curr->lft : curr->rgt;
        }
    }
    --sz;
    delete curr;
}

void BSTreeInt::eraseNodeWithTwoChildren(Node* curr, Node* prev, bool isLeft)
{
    Node* temp = curr;
    prev = curr;
    curr = curr->lft; //пошел налево
    while (curr->rgt) //ушел в самое правое
    {
        prev = curr; 
        curr = curr->rgt;
    }
    temp->data = curr->data;
    if (curr->lft)
    {
        eraseNodeWithOneChild(curr, prev, false);
    }
    else
    {
        eraseLeaf(curr, prev, false);
    }
}

string BSTreeInt::toStr(Node* r) const
{
    string result;
    if (r)
    {
        result += toStr(r->lft);
        result += " " + to_string(r->data);
        result += toStr(r->rgt);
    }
    return result;
}



void BSTreeInt::clear(Node* r)
{
    if (r)
    {
        clear(r->lft);
        clear(r->rgt);
        delete r->data;
        --sz;
    }
}