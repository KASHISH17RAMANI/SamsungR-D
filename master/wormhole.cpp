#include <iostream>
using namespace std;

int n;
int ans;
bool visited[100];

struct hole
{
    int x1, y1, x2, y2, cost;
};

struct point
{
    int x, y;
};

int calculate(point src, point dest)
{
    return (abs(src.x - dest.x) + abs(src.y - dest.y));
}

void solve(point src, point dest, hole a[], int cost)
{

    int tempans = cost + calculate(src, dest);
    cout << tempans << endl;
    ans = min(ans, tempans);

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {

            visited[i] = true;

            point temp1, temp2;
            int val;

            temp1.x = a[i].x1;
            temp1.y = a[i].y1;
            temp2.x = a[i].x2;
            temp2.y = a[i].y2;

            val = calculate(src, temp1);
            solve(temp2, dest, a, cost + val + a[i].cost);
            /* jab x1 le rha h to x2 k cordinates aur jab x1 le rha h to x1 k cordinates*/
            val = calculate(src, temp2);
            solve(temp1, dest, a, cost + val + a[i].cost);

            visited[i] = false;
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        point src, dest;
        cin >> src.x >> src.y >> dest.x >> dest.y;
        cin >> n;
        hole a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].cost;
        ans = 1000000;
        for (int i = 0; i < 100; i++)
            visited[i] = false;
        solve(src, dest, a, 0);
        cout << ans << endl;
    }

    return 0;
}