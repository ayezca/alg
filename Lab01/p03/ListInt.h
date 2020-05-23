#pragma once

#include <cstddef>
#include <string>
#include <utility>

class ListInt
{
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

    Node* head;
    Node* tail;
    std::size_t sz;

public:

    ListInt()
        : head(new Node(0, nullptr, nullptr))
        , tail(new Node(0, head, nullptr))
        , sz(0)
    {
        head->next = tail;
    }

    ListInt(const ListInt& other);
    ListInt& operator=(const ListInt& other);

    ~ListInt();


    void swap(ListInt& other)
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(sz, other.sz);
    }

    std::size_t size() const
    {
        return sz;
    }

    void pushBack(int x)
    {
        insertNode(tail, x);
    }

    std::string toStr() const;


    class Iter
    {
        friend class ListInt;

        Node* ptr;
        explicit Iter(Node* aPtr)
            : ptr(aPtr)
        {
        }

    public:

        int& operator*() const
        {
            return ptr->data;
        }

        Iter& operator++()
        {
            ptr = ptr->next;
            return *this;
        }

        Iter& operator--()
        {
            ptr = ptr->prev;
            return *this;
        }

        bool operator==(Iter other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(Iter other) const
        {
            return ptr != other.ptr;
        }
    };

    Iter begin()
    {
        return Iter(head->next);
    }

    Iter end()
    {
        return Iter(tail);
    }

    class RIter
    {
        friend class ListInt;

        Node* ptr;
        explicit RIter(Node* aPtr)
            : ptr(aPtr)
        {
        }

    public:

        int& operator*() const
        {
            return ptr->data;
        }

        RIter& operator++()
        {
            ptr = ptr->prev;
            return *this;
        }

        RIter& operator--()
        {
            ptr = ptr->next;
            return *this;
        }

        bool operator==(RIter other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(RIter other) const
        {
            return ptr != other.ptr;
        }
    };

    RIter rbegin()
    {
        return RIter(tail->prev);
    }

    RIter rend()
    {
        return RIter(head);
    }

private:
    Node* eraseNode(Node* p)
    {
        Node* r = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --sz;
        return r;
    }

    Node* insertNode(Node* p, int x)
    {
        Node* t = new Node(x, p->prev, p);
        p->prev->next = t;
        p->prev = t;
        ++sz;
        return p->prev;
    }

public:
    Iter erase(Iter p)
    {
        return Iter(eraseNode(p.ptr));
    }

    Iter insert(Iter p, int x)
    {
        return Iter(insertNode(p.ptr, x));
    }

#ifdef AU_DEBUG
    static int deleteCount;
#endif
};