#include <iostream>
using namespace std;

int n;
int a[15][5];
int ans;

int dx[] = {-1, 0, 1};

bool valid(int r, int c)
{
    return (c >= 0 && c < 5 && r >= 0 && r < n);
}

void solve(int r, int c, int points, int power, int magic)
{

    /* important to find the max at every call
     to get the intermediate maximum also*/
    ans = max(ans, points);

    if (r == 0)
    {
        ans = max(ans, points);
        return;
    }

    for (int i = 0; i < 3; i++)
    {

        int y = c + dx[i];
        int x = r - 1;

        if (valid(x, y))
        {
            if (a[x][y] == 2)
            {
                if (magic)
                {
                    solve(x, y, points, 5, 0);
                }
                if (points > 0)
                    solve(x, y, points - 1, power - 1, magic);

                if (power > 0)
                    solve(x, y, points, power - 1, 0);

                /*base case  don't forget this*/
                if (points == 0 && power <= 0 && magic == 0)
                {
                    ans = max(ans, points);
                    return;
                }
            }

            if (a[x][y] == 1)
                solve(x, y, points + 1, power - 1, magic);
            if (a[x][y] == 0)
                solve(x, y, points, power - 1, magic);
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> a[i][j];
            }
        }

        ans = -1;
        solve(n, 2, 0, 0, 1);
        if (ans == 0)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}