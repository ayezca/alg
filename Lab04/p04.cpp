#include <iostream>
#include <string>

using namespace std;

void towers(int n, string source, string temp, string dest)
{
    if (n > 0)
    {
        towers(n - 1, source, dest, temp);
        cout << source << "->" << dest << endl;
        towers(n - 1, temp, source, dest);
    }
}

int main()
{
    int n;
    cin >> n;
    
    towers(n, "source", "temp", "dest");
}