#include <iostream>
using namespace std;

int *FindExitPoint(int n, int m, int matrix[][100])
{
    int x[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Movement directions: right, down, left, up
    int dir = 0;                                      // Initial direction is right
    int i = 0, j = 0;                                 // Starting position

    while (true)
    {
        if (matrix[i][j] == 0)
        {
            i += x[dir][0];
            j += x[dir][1];
        }
        else
        {
            dir = (dir + 1) % 4; // Change direction clockwise
            matrix[i][j] = 0;    // Mark cell as visited
            i += x[dir][0];
            j += x[dir][1];
        }

        // Check if out of bounds
        if (i >= n || j >= m || i < 0 || j < 0)
        {
            break;
        }
    }

    // Adjust to last valid position
    i -= x[dir][0];
    j -= x[dir][1];

    int *result = new int[2]; // Allocate result array dynamically
    result[0] = i;
    result[1] = j;
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int matrix[100][100]; // Maximum size as per constraints, assuming max 100x100
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int *result = FindExitPoint(n, m, matrix);

    cout << result[0] << " " << result[1] << endl;

    delete[] result; // Free allocated memory
    return 0;
}
