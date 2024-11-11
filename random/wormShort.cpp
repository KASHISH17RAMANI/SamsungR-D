#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

struct Point
{
    int x, y;
};

struct Wormhole
{
    Point entry, exit;
    int cost;
};

int calculateDistance(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int findMinCost(Point S, Point D, Wormhole wormholes[], int N, bool used[])
{
    int minCost = calculateDistance(S, D);

    for (int i = 0; i < N; ++i)
    {
        if (!used[i])
        {
            used[i] = true;

            int costUsingEntry = calculateDistance(S, wormholes[i].entry) + wormholes[i].cost + findMinCost(wormholes[i].exit, D, wormholes, N, used);
            int costUsingExit = calculateDistance(S, wormholes[i].exit) + wormholes[i].cost + findMinCost(wormholes[i].entry, D, wormholes, N, used);

            minCost = min(minCost, min(costUsingEntry, costUsingExit));

            used[i] = false;
        }
    }

    return minCost;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;

        Point S, D;
        cin >> S.x >> S.y >> D.x >> D.y;

        Wormhole wormholes[N];
        for (int i = 0; i < N; ++i)
        {
            cin >> wormholes[i].entry.x >> wormholes[i].entry.y >> wormholes[i].exit.x >> wormholes[i].exit.y >> wormholes[i].cost;
        }

        bool used[N] = {false};
        int result = findMinCost(S, D, wormholes, N, used);

        cout << result << endl;
    }

    return 0;
}