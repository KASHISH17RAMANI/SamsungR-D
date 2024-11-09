#include <iostream>
using namespace std;

int main()
{
    // allocate 3d arrya dynamically
    int x, y, z;
    cin >> x >> y >> z;

    int ***arr = new int **[x]; // 2d array ko pint karne wale xpointers leliye

    for (int i = 0; i < x; i++)
    {
        arr[i] = new int *[y]; // eaxh of x pointer will pooint to an arra of y pointers
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = new int[z]; // asosociuate with each of y pointer will be an matri of sinze z
            for (int k = 0; k < z; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    for (int i = 0; i < x; i++)
    {

        for (int j = 0; j < y; j++)
        {

            for (int k = 0; k < z; k++)
            {
                cout << arr[i][j][k];
            }
        }
    }
}