#include <iostream>
using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int **matrix = new int *[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    }

    int x, y;
    cin >> x >> y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (abs(x - i) == abs(y - j))
            {
                matrix[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            {
                cout << matrix[i][j];
            }
        }
    }
    return 0;
}
