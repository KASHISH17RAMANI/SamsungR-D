#include <bits/stdc++.h>
using namespace std;
int a[500][500];
bool visited[500][500];
int len[500][500];
int rows, cols;
int X[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int Y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct s
{
    int r, c;
};

bool valid(int r, int c)
{
    if (r < rows && c < cols && r >= 0 && c >= 0)
        return true;
    return false;
}

int calculate()
{
    int ans = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ans += len[i][j];
    return ans;
}

int solve(int r, int c)
{
    queue<s> q;
    s temp;
    temp.r = r;
    temp.c = c;
    q.push(temp);
    visited[r][c] = true;
    len[r][c] = 1;

    while (!q.empty())
    {
        s topp = q.front();
        int R = topp.r;
        int C = topp.c;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = R + X[i];
            int y = C + Y[i];
            if (valid(x, y))
                if (a[x][y] == 1 && visited[x][y] == false)
                {
                    s temp1;
                    temp1.r = x;
                    temp1.c = y;
                    q.push(temp1);
                    len[x][y] = 1;
                    visited[x][y] = true;
                }
        }
    }
    return calculate();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        memset(visited, 0, sizeof(visited));
        cin >> rows >> cols;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> a[i][j];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (a[i][j] == 1 && visited[i][j] == false)
                {
                    memset(len, 0, sizeof(len));
                    ans = max(ans, solve(i, j));
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}