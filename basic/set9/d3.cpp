#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ***d3 = new int **[x];
    for (int i = 0; i < x; i++)
    {
        d3[i] = new int *[y];
        for (int j = 0; j < y; j++)
        {
            d3[i][j] = new int[z];
            for (int k = 0; k < z; k++)
            {
                cin >> d3[i][j][k];
            }
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << d3[i][j][k];
            }
        }
    }
}