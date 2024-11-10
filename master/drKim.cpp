#include <bits/stdc++.h>
using namespace std;
int visited[40] = {0};
struct cord
{
    int x;
    int y;
};

int solve(cord a[], int n, int x, int y, int index, int hx, int hy, int cnt)
{

    if (cnt == n)
        return abs(x - hx) + abs(y - hy);

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cord c = a[i];
        if (!visited[i])
        {
            visited[i] = 1;
            int val = abs(x - c.x) + abs(y - c.y);
            ans = min(ans, val + solve(a, n, c.x, c.y, i, hx, hy, cnt + 1));
            visited[i] = 0;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cord p[n];
        int ox, oy;
        cin >> ox >> oy;
        int hx, hy;
        cin >> hx >> hy;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            cord a;
            a.x = x;
            a.y = y;
            p[i] = a;
        }
        // int ans = 0;
        int ans = solve(p, n, ox, oy, 0, hx, hy, 0);
        cout << ans << endl;
    }

    return 0;
}