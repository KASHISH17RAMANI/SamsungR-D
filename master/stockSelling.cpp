#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define int long long

int dp[100][100][100];

int solve(int *a, int s, int e, int k)
{

    // base case
    if (s >= e)
        return 0;
    if (k == 0)
        return 0;
    if (dp[s][e][k] != -1)
        return dp[s][e][k];
    int ans = 0;

    for (int i = s; i < e; i++)
    {

        for (int j = i + 1; j <= e; j++)
        {
            int temp = 0;

            if (a[j] > a[i])
            {
                temp += a[j] - a[i] + solve(a, j + 1, e, k - 1);
            }
            ans = max(ans, temp);
        }
    }
    return dp[s][e][k] = ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        memset(dp, -1, sizeof(dp));
        cout << solve(a, 0, n - 1, k) << endl;
    }
    return 0;
}