#include <bits/stdc++.h>
using namespace std;

int globalAns = INT_MAX;

void solve(int a[], int n, bool vis[], int LtoR, int ans, int visCnt)
{

    if (ans > globalAns)
        return; /* optimization */
    if (visCnt == n)
    { /*base case // all visited */
        // TO CHECK ALL THE ANSWERS SIMPLY PRINT THE ANS EVERYTIME
        globalAns = min(ans, globalAns);
    }

    if (LtoR == 1)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                if (vis[i] == false && vis[j] == false)
                {
                    int bada = max(a[i], a[j]);

                    /* backtracking logic */
                    vis[i] = true;
                    vis[j] = true;
                    solve(a, n, vis, 1 - LtoR, ans + bada, visCnt + 2);
                    vis[i] = false;
                    vis[j] = false;
                }
            }
        }
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == true)
            {
                /* backtracking logic */
                vis[i] = false;
                solve(a, n, vis, 1 - LtoR, ans + a[i], visCnt - 1);
                vis[i] = true;
            }
        }
    }
}

int main()
{

    int t;
    cin >> t;
    // solution by Ankit Mittal
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        bool vis[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            vis[i] = false;

        solve(a, n, vis, 1, 0, 0);
        cout << globalAns << endl;
    }
}
