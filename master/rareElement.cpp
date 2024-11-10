/*
remember the fucking indexing
5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

Output
#1 1
#2 2
#3 2
#4 12
#5 15


*/

#include <iostream>
using namespace std;

struct node
{
    int x;
    int y;
    int level;
};

node q[1000];
int front = 0, back = 0;

void init()
{
    front = back = 0;
}

void push(int x, int y, int level)
{
    q[back].x = x;
    q[back].y = y;
    q[back].level = level;
    back++;
}
node pop()
{
    return q[front++];
}
bool empty()
{
    return (front == back);
}

int a[100][100];
int rare[4][2];
int c;
int n;

bool valid(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int vis[100][100];

int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};

int bfs(int sx, int sy, int dx, int dy)
{

    push(sx, sy, 0);
    vis[sx][sy] = 1;

    while (!empty())
    {

        node temp = pop();
        if (temp.x == dx && temp.y == dy)
            return temp.level;

        for (int i = 0; i < 4; i++)
        {

            int valx = temp.x + xx[i];
            int valy = temp.y + yy[i];
            int lvl = temp.level + 1;

            if (valid(valx, valy))
            {
                if (a[valx][valy] == 1 && vis[valx][valy] == 0)
                {
                    push(valx, valy, lvl);
                    vis[valx][valy] = 1;
                }
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
        cin >> n;
        cin >> c;

        init();

        for (int i = 0; i < c; i++)
        {
            int x, y;
            cin >> x >> y;
            /*  indexing is so fucking important*/
            x--;
            y--;
            rare[i][0] = x;
            rare[i][1] = y;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        int ans = 10000;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp;
                if (a[i][j] == 1)
                {
                    temp = 0;

                    for (int k = 0; k < c; k++)
                    {
                        /*  fucking don't forgot to empty the queue */
                        init();
                        for (int l = 0; l < 100; l++)
                            for (int m = 0; m < 100; m++)
                                vis[l][m] = 0;
                        int res = bfs(i, j, rare[k][0], rare[k][1]);
                        temp = max(res, temp);
                    }
                    /* if k bahar mt likhio pehle galti se likh dia tha */
                    ans = min(ans, temp);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}