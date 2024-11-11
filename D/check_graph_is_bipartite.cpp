#include <iostream>
using namespace std;

bool is_bipartite(int arr[][100], int n, int i, int color[])
{
    for (int j = 0; j < n; j++)
    {
        if (arr[i][j] == 1)
        { // If there's an edge between i and j
            if (color[j] == -1)
            {                            // If the node hasn't been colored yet
                color[j] = 1 - color[i]; // Color it with the opposite color
                // Recursively check if the graph remains bipartite
                if (!is_bipartite(arr, n, j, color))
                {
                    return false; // Return false if any conflict is found
                }
            }
            else if (color[i] == color[j])
            {                 // If adjacent nodes have the same color
                return false; // The graph is not bipartite
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    int arr[100][100];
    int color[100];
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    // Read the adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Try to color the graph and check if it's bipartite
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {                 // If node i is not yet colored
            color[i] = 0; // Start coloring with color 0
            if (!is_bipartite(arr, n, i, color))
            {
                cout << "-1" << endl; // If it's not bipartite, print -1
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            cout << i << " ";
        }
    }

    cout << "\n______________\n";
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 1)
        {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
