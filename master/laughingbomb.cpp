#include <iostream>
using namespace std;

struct node
{
    int x;
    int y;
    int l;
};

int sx, sy;
node q[100000];
bool vis[1000][1000];
int front, back;
int n, m;
int a[100][100];
int ans;

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

bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve()
{

    if (a[sx][sy] == 0)
        return;

    vis[sx][sy] = true;
    push(sx, sy, 1);

    while (!empty())
    {

        node temp = pop();

        int x, y, l;
        x = temp.x;
        y = temp.y;
        l = temp.l;

        ans = max(ans, l);

        for (int i = 0; i < 4; i++)
        {

            int xx = x + dx[i];
            int yy = y + dy[i];

            if (valid(xx, yy) && a[xx][yy] == 1)
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

        /* FIRST COLUMN IS TAKEN AS INPUT AND THEN ROW ACC. TO TEST CASES */
        cin >> m >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
                cin >> a[i][j];
            }
        }
        /* acc to the test cases first col is taken as input and then row
           I have taken the input as row and then col so write it down as
           cin>>sy>>sx
        */
        cin >> sx >> sy;
        sx--;
        sy--; /* zero based indexing */
        init();
        ans = -1;
        solve();
        cout << ans << endl;
    }

    return 0;
}