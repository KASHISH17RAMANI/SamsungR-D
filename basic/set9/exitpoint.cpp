#include <iostream>
using namespace std;

int *FindExitPoint(int n, int m, int **matrix)
{
    int x[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0;
    int i = 0, j = 0;

    while (true)
    {
        if (matrix[i][j] == 0)
        {
            i += x[dir][0];
            j += x[dir][1];
        }
        else
        {
            dir = (dir + 1) % 4;
            matrix[i][j] = 0;
            i += x[dir][0];
            j += x[dir][1];
        }

        if (i >= n || j >= m || i < 0 || j < 0)
        {
            break;
        }
    }

    // Move back to the last valid position
    i -= x[dir][0];
    j -= x[dir][1];

    int *exitPoint = new int[2]; // Allocate an array to store the exit coordinates
    exitPoint[0] = i;
    exitPoint[1] = j;
    return exitPoint; // Return the pointer to the array
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        // Dynamic allocation of matrix
        int **matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int *exitPoint = FindExitPoint(n, m, matrix);
        cout << exitPoint[0] << " " << exitPoint[1] << "\n";

        // Free the dynamically allocated exit point and matrix
        delete[] exitPoint;
        for (int i = 0; i < n; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << "~\n";
    }
    return 0;
}
