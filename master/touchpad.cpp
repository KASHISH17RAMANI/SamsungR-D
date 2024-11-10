#include <bits/stdc++.h>
using namespace std;
int n, m, o, num;

int solve(int digits[], int sign[], int op, int val, int num)
{
    // base case
    if (op > o)
        return INT_MAX;
    if (val == num)
        return op;

    // recursive case
    int ans1 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int x = val * 10 + digits[i];
        ans1 = min(ans1, solve(digits, sign, op + 1, x, num));
    }

    int ans2 = INT_MAX;
    int x;
    for (int i = 0; i < n; i++)
    {
        if (sign[1] == 1)
            x = val + digits[i];
        ans2 = min(ans2, solve(digits, sign, op + 2, x, num));
        if (sign[2] == 1)
            x = val - digits[i];
        ans2 = min(ans2, solve(digits, sign, op + 2, x, num));
        if (sign[3] == 1)
            x = val * digits[i];
        ans2 = min(ans2, solve(digits, sign, op + 2, x, num));
        if (sign[4] == 1)
            x = val / digits[i];
        ans2 = min(ans2, solve(digits, sign, op + 2, x, num));
    }
    if (ans2 != INT_MAX)
        ans2++;
    return min(ans1, ans2);
}

int main()
{

    cin >> n >> m >> o;
    int digits[n], sign[5] = {0};
    for (int i = 0; i < n; i++)
        cin >> digits[i];
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        sign[x]++;
    }
    cin >> num;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, solve(digits, sign, 1, digits[i], num));
    }
    if (ans != INT_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}