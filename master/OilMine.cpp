/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values. You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil mines adjacent to each other and not in between of each others.After distributing them compute the difference of oil mines from the company getting highest and company getting lowest. This number should be minimum.(then only the distribution can be termed as fair).

  Example
  Input
  2
  2 4
  6 13 10 2
  2 4
  6 10 13 2

  output
  5
  1

SPECIAL THANKS TO  MY FRINED MOHIT

*/

#include <iostream>
using namespace std;

int ans = 2e9;

void findDiff(int comp[], int n)
{
    int maxx = -1, minn = 2e9;
    for (int i = 0; i < n; ++i)
    {
        if (comp[i] < minn)
            minn = comp[i];
        if (comp[i] > maxx)
            maxx = comp[i];
    }
    if (maxx - minn < ans)
        ans = maxx - minn;
}

void solve(int curPos, int endPos, int comp[], int mines[], int n, int m, int companyNum, int remainingMines)
{
    if (remainingMines < n - companyNum)
        return; // remove if company can get 0 mines
    // if all companies have been assigned some mines
    if ((curPos + 1) % m == endPos)
    {
        // if last mine is remaining and last company is remaining
        if (companyNum == n - 1)
        {
            // assign last mine to last company and cmpute result
            comp[companyNum] += mines[curPos];
            findDiff(comp, n);
            // backtrack
            comp[companyNum] -= mines[curPos];
        }
        return;
    }

    if (companyNum >= n)
        return;

    // assign current mine to current company
    comp[companyNum] += mines[curPos];
    // solve for same company and next mine
    solve((curPos + 1) % m, endPos, comp, mines, n, m, companyNum, remainingMines - 1);
    // solve for next company and next mine
    solve((curPos + 1) % m, endPos, comp, mines, n, m, companyNum + 1, remainingMines - 1);

    // do not assign mine to current company (backtracking)
    comp[companyNum] -= mines[curPos];
    // solve for next company and current mine
    if (comp[companyNum] > 0) // if mine value can't be <= 0 (comment this condition if mine value can be <=0)
        solve(curPos, endPos, comp, mines, n, m, companyNum + 1, remainingMines);
}

int main()
{
    int n, m;
    // cin >> n >> m;
    n = 3, m = 3;

    // mines
    // int mines[m];
    int mines[m] = {1, 3, 3};
    // for (int i = 0; i < m; ++i) cin >> mines[i];

    // comp stores the total mine value assigned to a company
    int comp[n] = {0};
    if (n > m)
    { // remove this if a company can get 0 mines
        cout << "-1" << endl;
        return -1;
    }

    // start from all the places and solve for all possible ways to fill comp[]
    for (int i = 0; i < m; ++i)
    {
        solve(i, i, comp, mines, n, m, 0, m);
    }
    cout << ans << endl;

    return 0;
}