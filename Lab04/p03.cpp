#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

// gcd(10, 25) = 5
// gcd(40, 20) = 20
// gcd(0, 17) = 17
// gcd(0, 0) is not defined

// gcd(0, 0) is not defined
// gcd(a, 0) = a
// gcd(0, b) = b
// if a > 0, b > 0 gcd(a, b) = gcd(b, a % b)

// imperative
// declarative
int gcdAux(int a, int b)
{
    
    if (a == 0) return b;
    if (b == 0) return a;
    return gcdAux(b, a % b);
}

int gcd(int a, int b)
{
    if (a == 0 && b == 0)
    {
        throw invalid_argument("gcd(0, 0) is not defined");
    }
    
    return gcdAux(abs(a), abs(b));
}


int main()
{
    int a;
    int b;
    while (cin >> a >> b)
    {
        try
        {
            int r = gcd(a, b);
            cout << "gcd(" << a << "," << b << ") = " << r << endl;
        }
        catch (invalid_argument& e)
        {
            cout << e.what() << endl;
        }
    }
}