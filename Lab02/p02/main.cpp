#include <iostream>
#include <sstream>

#include "HashSetStr.h"

using namespace std;


size_t worstHashFunc(const string& s)
{
    return 42;
}

int main()
{
    HashSetStr words(11, worstHashFunc);
    
    auto hf = words.getHashFunc();
    
    string line;
    while (getline(cin, line))
    {
        istringstream sinp(line);
        string cmd;
        sinp >> cmd;
        if (cmd == "#")
        {
            words.debugPrint();
        }
        else if (cmd == "+")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hf(word) << endl;
            cout << "bucket's index: " << hf(word) % words.bucketsCount() << endl; 
            cout << (words.insert(word) ? "OK" : "already in the set") << endl;
        }
        else if (cmd == "-")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hf(word) << endl;
            cout << "bucket's index: " << hf(word) % words.bucketsCount() << endl; 
            cout << (words.erase(word) != 0 ? "OK" : "not in the list") << endl;
        }
        else if (cmd == "?")
        {
            string word;
            sinp >> word;
            cout << "hash value: " << hf(word) << endl;
            cout << "bucket's index: " << hf(word) % words.bucketsCount() << endl; 
            cout << (words.find(word) ? "found" : "not found") << endl;
        }
        else
        {
            cout << "unknown command" << endl;
        }
    }
}