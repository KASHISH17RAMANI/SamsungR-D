// Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
// the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump).
// A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only)
// with cost as the number of jumps taken.
// Given a source and destination, the frog has to reach the destination minimizing the cost (jump).

#include <iostream>
using namespace std;
#define QS 1000005
struct point
{
    int x;
    int y;
};

int n;
int source_x, source_y;
int destination_x, destination_y;
int matrix[105][105];
int distance1[105][105];
int visited[105][105];

int direction_x[] = {1, 0, -1, 0};
int direction_y[] = {0, 1, 0, -1};

point queue[QS];
int front = 0;
int rear = 0;

bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void solve()
{
    queue[rear].x = source_x;
    queue[rear].y = source_y;
    rear = (rear + 1) % QS;
    visited[source_x][source_y] = 1;
    distance1[source_x][source_y] = 0;
    while (front != rear)
    {
        int p = queue[front].x;
        int q = queue[front].y;
        front = (front + 1) % QS;

        for (int i = 0; i < 4; i++)
        {
            int new_x = p + direction_x[i];
            int new_y = q + direction_y[i];
            if (is_valid(new_x, new_y) && matrix[new_x][new_y] && !visited[new_x][new_y])
            {
                if (i == 0 || i == 2)
                {
                    distance1[new_x][new_y] = distance1[p][q];
                }
                else if (i == 1 || i == 3)
                {
                    distance1[new_x][new_y] = 1 + distance1[p][q];
                }
                visited[new_x][new_y] = 1;
                queue[rear].x = new_x;
                queue[rear].y = new_y;
                rear = (rear + 1) % QS;
            }
        }
    }
    cout << distance1[destination_x][destination_y] << endl;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            visited[i][j] = 0;
            distance1[i][j] = 0;
        }
    }
    cin >> source_x >> source_y >> destination_x >> destination_y;
    solve();
    return 0;
}
