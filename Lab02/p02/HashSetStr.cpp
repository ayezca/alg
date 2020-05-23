#include <iostream>

#include "HashSetStr.h"

using namespace std;

size_t defaultHashFunc(const string& s)
{
    size_t r = 0;
    for (auto c : s)
    {
        r = 31 * r + c;
    }
    return r;
}

HashSetStr::~HashSetStr()
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        while (buckets[i])
        {
            Node* t = buckets[i];
            buckets[i] = buckets[i]->next;
            delete t;
        }
    }
}

bool HashSetStr::insert(const string& s)
{
    if (buckets.size() == length)
    {
        rehash();
    }

    size_t index = hf(s) % buckets.size();

    for (Node* p = buckets[index]; p; p = p->next)
    {
        if (p->data == s)
        {
            return false;
        }
    }

    buckets[index] = new Node(s, buckets[index]);

    ++length;

    return true;
}


void HashSetStr::debugPrint() const
{
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        cout << i << ":";
        for (Node* p = buckets[i]; p; p = p->next)
        {
            cout << " " << p->data;
        }
        cout << "\n";
    }
}

bool HashSetStr::find(const std::string& e) const
{
    size_t index = hf(e) % buckets.size();

    for (Node* p = buckets[index]; p; p = p->next)
    {
        if (p->data == e)
        {
            return true;
        }
    }

    return false;
}


bool HashSetStr::erase(const std::string& e)
{
    size_t index = hf(e) % buckets.size();

    Node* prev = nullptr;
    for (Node* curr = buckets[index]; curr; curr = curr->next)
    {
        if (curr->data == e)
        {
            if (prev == nullptr)
            {
                buckets[index] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete curr;
            --length;
            return true;
        }
        prev = curr;
    }

    return false;
}


void HashSetStr::rehash()
{
    vector<Node*> newBuckets(buckets.size() * 2 + 1);
    for (size_t i = 0; i < buckets.size(); ++i)
    {
        for (Node* curr = buckets[i]; curr;)
        {
            size_t index = hf(curr->data) % newBuckets.size();
            Node* t = curr->next;
            curr->next = newBuckets[index];
            newBuckets[index] = curr;
            curr = t;
        }
    }
    buckets.swap(newBuckets);
}
