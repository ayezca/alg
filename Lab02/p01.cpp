#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

struct WorstHashFunc
{
    size_t operator()(const string& s) const
    {
        return 42;
    }
};

int main()
{
    
    unordered_set<string> words;
    //unordered_set<string, WorstHashFunc> words;
    
    auto hf = words.hash_function();
    
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        string cmd;
        sinp >> cmd;
        if (cmd == "#")
        {
            cout << "number of buckets: " << words.bucket_count() << endl;
            for (size_t i = 0; i < words.bucket_count(); ++i)
            {
                cout << setw(4) << i << ": ";
                for (auto p = words.begin(i); p != words.end(i); ++p)
                {
                    cout << *p << " ";
                }
                cout << endl;
            }
        }
        else if (cmd == "+")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hf(word) << endl;
            cout << "bucket's index: " << hf(word) % words.bucket_count() << endl; 
            cout << (words.insert(word).second ? "OK" : "already in the list") << endl;
        }
        else if (cmd == "-")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hf(word) << endl;
            cout << "bucket's index: " << hf(word) % words.bucket_count() << endl; 
            cout << (words.erase(word) != 0 ? "OK" : "not in the list") << endl;
        }
        else if (cmd == "?")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hf(word) << endl;
            cout << "bucket's index: " << hf(word) % words.bucket_count() << endl; 
            cout << (words.find(word) != words.end() ? "found" : "not found") << endl;
        }
        else
        {
            cout << "unknown command" << endl;
        }
    }
    
}