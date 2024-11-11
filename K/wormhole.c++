
#include <iostream>
using namespace std;

int ANS = 1e5, n, temp = 0;
int w[35][5];
int mask[35];

int abs(int i)
{
    return (i >= 0) ? i : -1 * i;
}

int min(int x, int y)
{
    return (x >= y) ? y : x;
}

int dist(int sX, int sY, int tX, int tY)
{
    return abs(sX - tX) + abs(sY - tY);
}

void wormhole(int sX, int sY, int tX, int tY, int value)
{
    ANS = min(ANS, dist(sX, sY, tX, tY) + value);

    for (int i = 0; i < n; i++)
    {
        if (mask[i] == 0)
        {
            mask[i] = 1;

            /* Choose lower end of wormhole */
            temp = dist(sX, sY, w[i][0], w[i][1]) + w[i][4] + value;
            wormhole(w[i][2], w[i][3], tX, tY, temp);

            /* Choose upper end of wormhole */
            temp = dist(sX, sY, w[i][2], w[i][3]) + w[i][4] + value;
            wormhole(w[i][0], w[i][1], tX, tY, temp);

            mask[i] = 0;
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t, sX, sY, tX, tY;
    cin >> t;
    while (t--)
    {
        ANS = 1e5;
        cin >> n;
        cin >> sX >> sY >> tX >> tY;
        for (int i = 0; i < n; i++)
        {
            mask[i] = 0;
            for (int j = 0; j < 5; j++)
            {
                cin >> w[i][j];
            }
        }

        wormhole(sX, sY, tX, tY, 0);
        cout << ANS << endl;
    }
    return 0;
}
