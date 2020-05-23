#pragma once

#include <string>
#include <utility>

class MapStrInt
{
public:

    MapStrInt()
        : root(nullptr), length(0)
    {
    }

    ~MapStrInt()
    {
        clear();
    }

    int& operator[](const std::string& k);

    void printInOrder() const
    {
        printInOrder(root);
    }

    void clear()
    {
        clear(root);
        length = 0;
    }

    int size() const
    {
        return length;
    }

private:

    struct Node
    {
        std::pair<std::string, int> data;
        Node* left;
        Node* right;

        Node(const std::string& k, int v, Node* aLeft, Node* aRight)
            : data(k, v), left(aLeft), right(aRight)
        {
        }
    };

    Node* root;
    int length;

    void printInOrder(Node* r) const;
    void clear(Node* r);
};
