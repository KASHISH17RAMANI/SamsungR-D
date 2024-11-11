// Given below are the raw materials quantities and their respective selling price(if sold as raw).

// D --> No of CPUs
// E --> No of memory chips
// F --> No of boards
// d --> Selling price of CPU
// e --> Selling price of Memory chips

// We are given N Computer configurations like below :
// Di, Ei, Fi, SPi, which are the CPU, Chips, Boards and one unit selling price for ith computer respectively.
// Our task is to maximize the final cost.
// Constraints:
// 1. Can use at Max 3 different Configurations
// 2. We can use 1 configuration multiple times
// 3. Remaining Inventories can be sold on its selling price

// Input:
// T --> Number of test cases.
// D E F d e --> Inventories
// N --> Total Configuration Count
// Di Ei Fi SPi
// ...
// Dn En Fn SPn

// 1<=T<=10
// 1<= D, E, F <= 100
// 1<= d, e <=100000
// 1<=N<=8

// Output:
// First Line print the Case #testCaseNumber
// Second Line Print Maximum Cost per test case in each line.

// Sample Input:
// 1 --> Total Test Case
// 10 10 10 2 1 --> D E F d e
// 1 --> PC Configuration Count
// 1 2 2 3 --> D1 E1 F1 SP1

// Sample Output:
// Case #1
// 30

#include <iostream>
using namespace std;

int D, E, F, d, e;
int config;
int ans = 0;
struct configuration
{
    int D, E, F, SPi;
};
configuration m[9];

void solve(int index, int count_a, int D, int E, int F, int cost)
{
    if (index >= config || count_a == 3)
    {
        cost += D * d + E * e;
        if (cost > ans)
        {
            ans = cost;
        }
        return;
    }
    solve(index + 1, count_a, D, E, F, cost);
    int i = 1;
    while (true)
    {
        if (D - m[index].D * i >= 0 && E - m[index].E * i >= 0 && F - m[index].F * i >= 0)
        {
            solve(index + 1, count_a + 1, D - m[index].D * i, E - m[index].E * i, F - m[index].F * i, cost * m[index].SPi * i);
            i++;
        }
        else
        {
            break;
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> D >> E >> F >> d >> e;
        cin >> config;
        for (int i = 0; i < config; i++)
        {
            cin >> m[i].D >> m[i].E >> m[i].F >> m[i].SPi;
        }
        solve(0, 0, D, E, F, 0);
        cout << ans << endl;
    }
    return 0;
}