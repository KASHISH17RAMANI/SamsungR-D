#include <bits/stdc++.h>
using namespace std;

int d, e;
int a[5][2];
int dp[1000][1000]; // dp array of dist , energy

int solve(int d, int e)
{

    // base case
    if (d == 0)
        return 0;

    if (dp[d][e] != 99999)
        return dp[d][e];

    // recursive case
    int ans = INT_MAX - 100000;

    for (int i = 0; i < 5; i++)
    {
        if (e >= a[i][1])
        {
            int temp = a[i][0] + solve(d - 1, e - a[i][1]);
            ans = min(ans, temp);
        }
    }

    return dp[d][e] = ans;
}

int main()
{

    cin >> d >> e;

    for (int i = 0; i < 5; i++)
        cin >> a[i][0] >> a[i][1]; // corresponds to time and energy

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            dp[i][j] = 99999;

    cout << solve(d, e) << endl;

    return 0;
}