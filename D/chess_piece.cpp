// There is a mobile piece and a stationary piece on the N×M chessboard.
// The available moves of the mobile piece are the same as set out in the image below.
// You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.

// Write a program to find out the minimum number moves to catch a piece.

// [Input]
// Several test cases can be included in the inputs. T, the number of cases is given in the first row of the
// inputs. After that, the test cases as many as T (T ≤ 20) are given in a row.
// N, the numbers of the rows and M, the number of columns of the chessboard are given in the first row of
// each test case.
// R & C is the location information of the attacking piece and S & K is the location of the defending pieces
// and are given in the row at the second line. However, the location of the uppermost end of the left end
// is (1, 1)

// [Output]
// For each test case, you should print "Case #T" in the first line where T means the case number.

// For each test case, you should output the minimum number of movements to catch a defending piece at the
// first line of each test case. If not moveable, output equals ‘-1’.

// [I/O Example]

// Input
// 2
// 9 9
// 3 5 2 8
// 20 20
// 2 3 7 9

// Output
// Case #1
// 2
// Case #2
// 5

#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

typedef struct
{
    int x;
    int y;
    int level;
} data;

int moves[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, r1, c1, r2, c2;
        cin >> n >> m;
        int a[n + 1][m + 1];
        memset(a, 0, sizeof(int) * (n + 1) * (m + 1));
        cin >> r1 >> c1 >> r2 >> c2;
        data d, d1, d2;
        queue<data> q;
        d.x = r1;
        d.y = c1;
        d.level = 0;
        q.push(d);
        a[d.x][d.y] = 2;
        int temp_x, temp_y, temp_level;
        int steps = 0;
        bool f = false;
        while (!q.empty())
        {
            if (f)
            {
                break;
            }
            d1 = q.front();
            q.pop();
            for (int k = 0; k < 8; k++)
            {
                temp_x = d1.x + moves[k][0];
                temp_y = d1.y + moves[k][1];
                temp_level = d1.level + 1;
                if (temp_x >= 1 && temp_x <= n && temp_y >= 1 && temp_y <= m && a[temp_x][temp_y] == 0)
                {
                    if (temp_x == r2 && temp_y == c2)
                    {
                        steps = temp_level;
                        f = true;
                        break;
                    }
                    d2.x = temp_x;
                    d2.y = temp_y;
                    d2.level = temp_level;
                    q.push(d2);
                    a[d2.x][d2.y] = 2;
                }
            }
        }
        if (!f)
        {
            steps = -1;
        }
        cout << steps << endl;
    }
    return 0;
}
