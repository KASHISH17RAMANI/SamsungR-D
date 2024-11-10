#include <bits/stdc++.h>
using namespace std;

int pos[4]; // pos represent the position of the slots
int val[4]; // values corresponds to the number of fishermens
int a[1000];

int n, ans = INT_MAX;
/* finding the nearest right empty position*/
int posRight(int index)
{
    for (int i = index; i <= n; i++)
        if (a[i] == 0)
            return i;
    return INT_MAX;
}

/*finding the nearest left most empty position*/
int posLeft(int index)
{
    for (int i = index - 1; i > 0; i--)
        if (a[i] == 0)
            return i;
    return INT_MAX;
}

void solve(int x, int y, int z, int currPos, int cost)
{

    if (cost > ans)
        return;

    if (val[currPos] == 0)
    {
        if (currPos == x)
            currPos = y;
        else if (currPos == y)
            currPos = z;
        else
        {
            ans = min(ans, cost);
            return;
        }
    }

    int l = posLeft(pos[currPos]);
    int ll = abs(pos[currPos] - l + 1);
    int r = posRight(pos[currPos]);
    int rr = abs(r - pos[currPos] + 1);

    int distance = ll > rr ? r : l;
    int tempx = min(ll, rr);

    /* in case of last position if there is equal distance of left and right then check for
       both the cases any of the following will give the optimal results*/

    if (val[currPos] == 1 && ll == rr)
    {

        a[l] = 1;
        val[currPos]--;
        solve(x, y, z, currPos, cost + ll);
        a[l] = 0;
        val[currPos]++;

        a[r] = 1;
        val[currPos]--;
        solve(x, y, z, currPos, cost + rr);
        a[r] = 0;
        val[currPos]++;
    }

    /* optimization is done here we are choosing the pos which is near*/
    else
    {
        a[distance] = 1;
        val[currPos]--;
        solve(x, y, z, currPos, cost + tempx);
        a[distance] = 0;
        val[currPos]++;
    }
}

void init()
{
    for (int i = 0; i < 1000; i++)
        a[i] = 0;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; t--)
    {

        cin >> n;

        for (int i = 1; i <= 3; i++)
            cin >> pos[i] >> val[i];

        ans = INT_MAX;
        init();

        solve(1, 2, 3, 1, 0);
        init();
        solve(1, 3, 2, 1, 0);
        init();
        solve(2, 3, 1, 2, 0);
        init();
        solve(2, 1, 3, 2, 0);
        init();
        solve(3, 1, 2, 3, 0);
        init();
        solve(3, 2, 1, 3, 0);
        init();

        cout << ans << endl;
    }

    return 0;
}