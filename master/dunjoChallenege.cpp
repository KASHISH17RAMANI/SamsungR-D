#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[i - 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int k = i + 1;
        dp[i][k] = max(a[i - 1], a[k - 1]);
    }
    for (int len = 3; len <= n; len++)
    {
        for (int left = 1; left <= n - len + 1; left++)
        {
            int right = left + len - 1;
            int x = a[left - 1] + max(dp[left + 2][right], dp[left + 1][right - 1]);
            int y = a[right - 1] + max(dp[left][right - 2], dp[left + 1][right - 1]);
            dp[left][right] = max(x, y);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}