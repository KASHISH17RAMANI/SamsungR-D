#include <iostream>
using namespace std;

// Queue class to hold the coordinates and distance for BFS traversal
class Queue
{
private:
    int data[400][3]; // Each element will store {x, y, dist}
    int front, rear;

public:
    Queue() : front(0), rear(0) {}

    // Enqueue function
    void enqueue(int x, int y, int dist)
    {
        data[rear][0] = x;
        data[rear][1] = y;
        data[rear][2] = dist;
        rear++;
    }

    // Dequeue function
    void dequeue(int &x, int &y, int &dist)
    {
        x = data[front][0];
        y = data[front][1];
        dist = data[front][2];
        front++;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == rear;
    }
};

// BFS function without STL
int bfs(int matrix[][5], int srcx, int srcy, int dstx, int dsty, int n, int m)
{
    // If the start or destination is not a road, return -1
    if (matrix[srcx][srcy] == 0 || matrix[dstx][dsty] == 0)
        return -1;

    // Direction arrays for moving up, down, left, and right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Initialize visited array
    int visited[20][20] = {0}; // assuming max matrix size as 20x20
    visited[srcx][srcy] = 1;

    // Initialize queue for BFS
    Queue queue;
    queue.enqueue(srcx, srcy, 0);

    while (!queue.isEmpty())
    {
        // Dequeue the next node's coordinates and distance
        int x, y, dist;
        queue.dequeue(x, y, dist);

        // Check if reached destination
        if (x == dstx && y == dsty)
            return dist;

        // Explore all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Check if new position is within bounds, is a '1' (road), and not visited
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && matrix[newX][newY] == 1 && !visited[newX][newY])
            {
                visited[newX][newY] = 1;
                queue.enqueue(newX, newY, dist + 1);
            }
        }
    }

    // If destination is unreachable
    return -1;
}

int main()
{
    int m = 5;
    int n = 5;
    int matrix[5][5] = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, 1, 1, 0, 1}, {1, 1, 1, 1, 1}};
    int rare[2][2] = {{4, 3}, {3, 4}};
    int mini = 1e9;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 1)
            { // Only consider roads
                int maxi = -1;

                bool allReachable = true;
                for (int k = 0; k < 2; k++)
                {
                    int distance = bfs(matrix, i, j, rare[k][0], rare[k][1], n, m);
                    if (distance == -1)
                    {
                        allReachable = false;
                        break;
                    }
                    maxi = max(maxi, distance);
                }

                if (allReachable)
                {
                    mini = min(mini, maxi);
                }
            }
        }
    }

    cout << (mini == 1e9 ? -1 : mini) << endl;
}