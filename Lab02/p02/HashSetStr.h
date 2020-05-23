#pragma once

#include <string>
#include <vector>

size_t defaultHashFunc(const std::string& s);

class HashSetStr
{
    //typedef size_t (*HashFunc)(const std::string& s);
    
    using HashFunc = std::size_t (*)(const std::string& s);
    
    struct Node
    {
        std::string data;
        Node* next;
        Node(const std::string& aData, Node* aNext)
            : data(aData)
            , next(aNext)
        {
        }
    };
    
    std::vector<Node*> buckets;
    std::size_t length;
    HashFunc hf;
    
    void rehash();
    
public:
    HashSetStr(std::size_t initBucketsSize = 3, HashFunc aHF = defaultHashFunc)
        : buckets(initBucketsSize, nullptr)
        , length(0)
        , hf(aHF)
    {
    }

    HashSetStr(const HashSetStr& other) = delete;
    HashSetStr& operator=(const HashSetStr& other) = delete;

    ~HashSetStr();
    
    std::size_t size() const
    {
        return length;
    }
    
    std::size_t bucketsCount() const
    {
        return buckets.size();
    }
    
    HashFunc getHashFunc() const
    {
        return hf;
    }
    
    
    void debugPrint() const;
    
    bool insert(const std::string& e);
    
    bool find(const std::string& e) const;
    
    bool erase(const std::string& e);
};