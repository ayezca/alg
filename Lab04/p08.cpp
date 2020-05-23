#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;


class Solver
{
    struct Frame
    {
        int c;
        int r;
        Frame(int aR, int aC)
            : r(aR)
            ,  c(aC)
        {
        }
    };
    
    int n;
    int counter;
    vector<int> solution;
    vector<int> rows;
    vector<int> diag1;
    vector<int> diag2;
    
    bool check(int r, int c)
    {
        return !rows[r] && !diag1[r - c + n - 1] && !diag2[r + c]; 
    }
    
    void putQueen(int r, int c)
    {
        rows[r] = diag1[r - c + n - 1] = diag2[r + c] = 1;
        solution[c] = r;
    }
    
    void takeQueen(int r, int c)
    {
        rows[r] = diag1[r - c + n - 1] = diag2[r + c] = 0;
    }
    
    void printSolution()
    {
        cout << ++counter << ":";   
        for (auto r : solution)
        {
            cout << " " << r;
        }
        cout << endl;
    }
    
    void solve(int c)
    {
        if (c == n)
        {
            printSolution();
        }
        else
        {
            for (int r = 0; r < n; ++r)
            {
                if (check(r, c))
                {
                    putQueen(r, c);
                    solve(c + 1);
                    takeQueen(r, c);    
                }
            }
        }
    }

public:

    Solver(int aN)
        : n(aN)
        , counter(0)
    {
        if (n < 1)
        {
            throw runtime_error("Solver: incorrect n");
        }
        
        solution.resize(n);
        rows.resize(n);
        diag1.resize(2 * n - 1);
        diag2.resize(2 * n - 1);
    }

    void run()
    {
        solve(0);
    }
    
    void runIter()
    {
        vector<Frame> stk; 
        
        stk.emplace_back(0, 0);
        while (!stk.empty())
        {
            if (stk.back().c == n)
            {
                printSolution();
                stk.pop_back();
                takeQueen(stk.back().r, stk.back().c);
                ++stk.back().r;
            }
            else if (stk.back().r == n)
            {
                stk.pop_back();
                if (!stk.empty())
                {
                    takeQueen(stk.back().r, stk.back().c);
                    ++stk.back().r;
                }
            }
            else if (check(stk.back().r, stk.back().c))
            {
                putQueen(stk.back().r, stk.back().c);
                stk.emplace_back(0, stk.back().c + 1);
            }
            else
            {
                ++stk.back().r;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Solver solver(n);

    solver.runIter();
}