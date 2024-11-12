// You are busy to promote a newly released film in a movie theater.
// The title is ‘Biochemical Laughing Bomb’ which is about terror.
// Guerrillas drop a biochemical laughing bomb in the middle of a city.
// Once exposed, you have to laugh all your life. The bomb will contaminate
//  four people around it during 1 second, and another four around each of
//  them during another one second. However, you won’t be contaminated if
//  you are not in the adjacent four directions. as the below shows the
//  location of the bomb and affected people, and shows contamination
//  process in seconds and you can figure out that the whole city is
//  contaminated in 8 seconds.
// In order to protect the city from the epidemic, create a program that
// figures out when the city will be contaminated by the bomb for the last.

// Time limit: 1 second (java: 2 seconds)

// [Input]
// Several test cases can be included in the inputs. T, the number of
// cases is given in the first row of the inputs. After that, the test cases
//  as many as T (T ≤ 30) are given in a row.
// The row and column of the city, N and M are given by being separated
//  with a blank on the first row of each test case. (1 ≤ N, M ≤ 100)
// The status within city is given by being separated with a blank from
// the second row to N number rows. 1 means people exist and 0 means people
// do not exist.
// The coordinate of the row and column on which the bomb fall is given
// by being separated with a blank on the last row.

// [Output]
// For each test case, you should print "Case #T" in the first line
// where T means the case number. For each test case, you should output
// how long does it take to contaminate al people on the first row of each
//  test case.

// [I/O Example]

// Input
// 2
// 7 8
// 0 0 1 1 0 0 0
// 1 1 1 1 0 1 0
// 0 0 1 1 1 1 1
// 0 1 1 1 1 1 1
// 0 1 0 0 1 1 0
// 0 1 1 1 1 0 0
// 0 0 1 0 1 1 1
// 0 0 0 0 1 0 0
// 2 5
// 10 10
// 1 1 1 1 0 1 1 0 0 0
// 0 1 1 1 1 1 0 1 1 0
// 0 0 1 1 0 1 0 1 1 1
// 0 1 1 1 1 1 0 0 1 1
// 0 1 0 1 0 1 1 1 1 0
// 0 0 0 0 0 1 1 0 0 0
// 1 0 1 0 1 0 1 1 0 0
// 0 0 1 1 1 1 1 1 1 1
// 1 0 1 0 0 1 0 1 1 0
// 1 1 1 0 0 0 0 1 1 1
// 2 2

// Output
// Case #1

// 8

// Case #2
// 21

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
int city[MAX_N][MAX_M];    // City grid (0 for empty, 1 for people)
int visited[MAX_N][MAX_M]; // Visited flag array to track contamination status

// Direction vectors for moving in four directions (up, right, down, left)
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct Node
{
    int x, y, time; // x, y position and the contamination time at that point
};

void bfs(int n, int m, int r, int c)
{
    // Initialize the visited array and queue for BFS
    memset(visited, -1, sizeof(visited)); // Set all as unvisited (-1)
    queue<Node> q;

    // Start from the bomb position, adjust to 0-based index
    q.push({r - 1, c - 1, 0}); // (x, y, time)
    visited[r - 1][c - 1] = 0; // The time to contaminate the bomb itself is 0

    int maxTime = 0; // Variable to track the maximum contamination time

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        // Explore the four directions
        for (int dir = 0; dir < 4; dir++)
        {
            int newX = current.x + dx[dir];
            int newY = current.y + dy[dir];

            // Check if the new position is within bounds and contains people (1)
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && city[newX][newY] == 1)
            {
                // If the person hasn't been visited yet or can be contaminated at an earlier time
                if (visited[newX][newY] == -1)
                {
                    visited[newX][newY] = current.time + 1;
                    maxTime = max(maxTime, visited[newX][newY]);
                    q.push({newX, newY, current.time + 1});
                }
            }
        }
    }

    cout << maxTime +1<< endl; // Output the maximum time to contaminate all reachable people
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> city[i][j];
            }
        }
        int r, c;
        cin >> r >> c;
        cout << "Case #" << t << ": ";
        bfs(N, M, r, c);
    }
    return 0;
}
