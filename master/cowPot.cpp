#include <iostream>
using namespace std;
#define int uint64_t
int n, z;
int a[1009];
int dp[1009][1009];
int ans;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void sort()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

int solve()
{

    for (int i = 1; i <= n; i++)
        dp[i][1] = a[i] * (n - i + 1);

    for (int i = n; i > 0; i--)
        for (int j = 2; j <= z; j++)
            for (int k = i + 1; k <= n; k++)
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + (k - i) * a[i]);

    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][z]);

    return ans;
}

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> z;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        sort();

        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                dp[i][j] = 10000000;

        ans = 1000000;
        cout << solve() << endl;
    }
    return 0;
}