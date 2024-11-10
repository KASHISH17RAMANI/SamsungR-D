#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

#define MAX_POINTS 20 // Adjust as necessary; each wormhole adds 2 nodes
#define INF numeric_limits<int>::max()

struct Point
{
    int x, y;
};

struct Wormhole
{
    Point entry, exit;
    int cost;
};

// Calculate Manhattan distance between two points
int manhattanDistance(const Point &p1, const Point &p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

// Dijkstra's algorithm to find the shortest path
int dijkstra(int n, int dist[MAX_POINTS][MAX_POINTS], int src, int dest)
{
    int minDist[MAX_POINTS];
    bool visited[MAX_POINTS] = {0};
    for (int i = 0; i < n; i++)
        minDist[i] = INF;
    minDist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;

        if (minDist[u] == INF)
            break;
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (dist[u][v] != INF && minDist[u] + dist[u][v] < minDist[v])
            {
                minDist[v] = minDist[u] + dist[u][v];
            }
        }
    }
    return minDist[dest];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n; // Number of wormholes
        cin >> n;

        Point src, dest;
        cin >> src.x >> src.y >> dest.x >> dest.y;

        Wormhole wormholes[n];
        for (int i = 0; i < n; i++)
        {
            cin >> wormholes[i].entry.x >> wormholes[i].entry.y >> wormholes[i].exit.x >> wormholes[i].exit.y >> wormholes[i].cost;
        }

        // Number of nodes (S, D, and 2 per wormhole)
        int numPoints = 2 + 2 * n;
        Point points[numPoints];
        points[0] = src;
        points[1] = dest;

        for (int i = 0; i < n; i++)
        {
            points[2 + 2 * i] = wormholes[i].entry;
            points[3 + 2 * i] = wormholes[i].exit;
        }

        // Distance matrix initialization
        int dist[MAX_POINTS][MAX_POINTS];
        for (int i = 0; i < numPoints; i++)
        {
            for (int j = 0; j < numPoints; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            }
        }

        // Populate the distance matrix with direct distances
        for (int i = 0; i < numPoints; i++)
        {
            for (int j = i + 1; j < numPoints; j++)
            {
                int d = manhattanDistance(points[i], points[j]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        // Add wormhole edges (bi-directional with specified cost)
        for (int i = 0; i < n; i++)
        {
            int entryIdx = 2 + 2 * i;
            int exitIdx = entryIdx + 1;
            dist[entryIdx][exitIdx] = wormholes[i].cost;
            dist[exitIdx][entryIdx] = wormholes[i].cost;
        }

        // Find the shortest path from S (0) to D (1)
        int result = dijkstra(numPoints, dist, 0, 1);
        cout << result << endl;
    }
    return 0;
}
