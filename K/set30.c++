#include <iostream>
#include <climits>

using namespace std;

struct Point
{
    int x, y;
};

// Function to calculate Manhattan distance
int manhattanDistance(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// Backtracking function to find the shortest path
void findShortestPath(Point locations[], bool visited[], int n, int pos, int count, int currentDist, int &minDist)
{
    // If all customers have been visited, return to home
    if (count == n)
    { // Exclude office and home from customer count
        currentDist += manhattanDistance(locations[pos], locations[1]);
        if (currentDist < minDist)
            minDist = currentDist;
        return;
    }

    // Try all unvisited customers
    for (int i = 2; i < n + 2; i++)
    { // Start from index 2, as 0 is office and 1 is home
        if (!visited[i])
        {
            visited[i] = true;
            findShortestPath(locations, visited, n, i, count + 1, currentDist + manhattanDistance(locations[pos], locations[i]), minDist);
            visited[i] = false;
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int n;
        cin >> n;

        Point locations[n + 2];        // Array to hold office, home, and customers
        bool visited[n + 2] = {false}; // Visited array initialized to false

        for (int i = 0; i < n + 2; ++i)
        {
            cin >> locations[i].x >> locations[i].y;
        }

        visited[0] = true; // Start at office
        int minDist = INT_MAX;

        // Start backtracking from the office at index 0, aiming to end at home (index 1)
        findShortestPath(locations, visited, n, 0, 0, 0, minDist);

        cout << "#" << t << " " << minDist << endl;
    }

    return 0;
}
