#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int solve(int *a, int n)
{

    for (int len = 1; len <= n; len++)
    {
        for (int left = 1; left <= n - len + 1; left++)
        {
            int right = left + len - 1;
            for (int k = left; k <= right; k++)
            {

                int temp = dp[left][k - 1] + dp[k + 1][right];
                if (left == 1 && right == n)
                    temp += a[k];
                else
                    temp += a[left - 1] * a[right + 1];
                dp[left][right] = max(dp[left][right], temp);
            }
        }
    }
    return dp[1][n];
}

int main()
{

    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 1;
    a[n + 1] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = 1;
    memset(dp, 0, sizeof(dp));
    cout << solve(a, n) << endl;
    return 0;
}