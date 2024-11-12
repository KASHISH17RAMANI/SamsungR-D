// There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze.
// You want to pick up the jewels after getting into the maze through the entrance and before getting
// out of it through the exit. You want to get as many jewels as possible, but you don’t want to take
// the same passage you used once.

// When locations of a maze and jewels are given, find out the greatest number of jewels you can get
// without taking the same passage twice, and the path taken in this case.

// Input
// There can be more than one test case in the input file. The first line has T, the number of test cases.
// Then the totally T test cases are provided in the following lines (T ≤ 10 ).

// In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given.
// The maze is N×N square-shaped. From the second line through N lines, information of the maze is given.
// “0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located
// on the upper-most left passage and the exit is located on the lower-most right passage.
// There is no case where the path from the entrance to the exit doesn’t exist.

// Output
// From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the
// greatest number of jewels that can be picked up. Each test case must be output separately as a empty.

#include <iostream>
#include <climits>
#define MAX 21
using namespace std;

int n, ans;

bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void printMatrix(int **arr)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int direction_x[] = {1, 0, -1, 0};
int direction_y[] = {0, 1, 0, -1};

void jewel_maze(int **maze, int x, int y, int value, int **visited, int **path)
{
    if (x == n - 1 && y == n - 1)
    {
        if (value >= ans)
        {
            ans = value;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[i][j])
                    {
                        path[i][j] = 3;
                    }
                    else
                    {
                        path[i][j] = maze[i][j];
                    }
                }
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + direction_x[i];
        int new_y = y + direction_y[i];
        if (is_valid(new_x, new_y))
        {

            if (visited[new_x][new_y] == 0 && maze[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                jewel_maze(maze, new_x, new_y, value, visited, path);
                visited[new_x][new_y] = 0;
            }

            if (visited[new_x][new_y] == 0 && maze[new_x][new_y] == 2)
            {
                visited[new_x][new_y] = 1;
                jewel_maze(maze, new_x, new_y, value + 1, visited, path);
                visited[new_x][new_y] = 0;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        int **maze = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            maze[i] = new int[n + 1];
        }

        int **visited = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            visited[i] = new int[n + 1];
        }

        int **path = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            path[i] = new int[n + 1];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
                visited[i][j] = 0;
                path[i][j] = 0;
            }
        }

        ans = INT_MIN;
        int source_x = 0;
        int source_y = 0;

        visited[source_x][source_y] = 1;
        if (maze[source_x][source_y] == 2)
        {
            jewel_maze(maze, source_x, source_y, 1, visited, path);
        }
        else
        {
            jewel_maze(maze, source_x, source_y, 0, visited, path);
        }
        cout << ans << endl;
        printMatrix(path);
    }
    return 0;
}

// 2
// 5
// 0 0 0 2 0
// 2 1 0 1 2
// 0 0 2 2 0
// 0 1 0 1 2
// 2 0 0 0 0
// 6
// 0 1 2 1 0 0
// 0 1 0 0 0 1
// 0 1 2 1 2 1
// 0 2 0 1 0 2
// 0 1 0 1 0 1
// 2 0 2 1 0 0