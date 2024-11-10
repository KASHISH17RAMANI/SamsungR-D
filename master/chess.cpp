#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
    int l;
};

node q[100000];
int front, back;

void init()
{
    front = back = 0;
}

void push(int x, int y, int l)
{
    q[back].x = x;
    q[back].y = y;
    q[back].l = l;
    back++;
}

node pop()
{
    return q[front++];
}

bool empty()
{
    return front == back;
}

int n, m;
int sx, sy, dx, dy;
bool vis[100][100];

int dex[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dey[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int solve()
{

    vis[sx][sy] = true;
    push(sx, sy, 0);

    while (!empty())
    {

        node temp = pop();
        int x = temp.x;
        int y = temp.y;
        int l = temp.l;

        if (x == dx && y == dy)
            return l;

        for (int i = 0; i < 8; i++)
        {

            int xx = x + dex[i];
            int yy = y + dey[i];

            if (valid(xx, yy) && !vis[xx][yy])
            {
                vis[xx][yy] = true;
                push(xx, yy, l + 1);
            }
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> sx >> sy >> dx >> dy;

        memset(vis, 0, sizeof(vis));
        init();
        cout << solve() << endl;
    }
    return 0;
}