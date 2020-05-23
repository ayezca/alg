#pragma once

#include <string>

class BSTreeInt
{
    struct Node
    {
        int data;
        Node* lft;
        Node* rgt;
        Node(int aData, Node* aLft, Node* aRgt)
            : data(aData)
            , lft(aLft)
            , rgt(aRgt)
        {
        }
    };

    Node* root;
    int sz;
    
    void clear(Node* r);
    std::string toStr(Node* r) const;
    void eraseLeaf(Node* curr, Node* prev, bool isLeft);
    void eraseNodeWithOneChild(Node* curr, Node* prev, bool isLeft);
    void eraseNodeWithTwoChildren(Node* curr, Node* prev, bool isLeft);

public:

#ifdef AUCA_DEBUG
    mutable std::string path;
#endif

    BSTreeInt()
        : root(nullptr)
        , sz(0)
    {
    }
    
    ~BSTreeInt() 
    {
        clear();
    }

    std::string toStr() const
    {
        return toStr(root);
    }
    
    int size() const
    {
        return sz;
    }
    
    bool insert(int k);
    
    bool find(int k) const;
    
    bool erase(int k);
    
    void clear()
    {
        clear(root);
    }
    
};