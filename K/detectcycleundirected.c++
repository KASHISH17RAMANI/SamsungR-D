#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int i, int **adj, int *vis, int parent, int V)
    {
        vis[i] = 1;

        for (int j = 0; j < V; ++j)
        {
            if (adj[i][j] == 1)
            { // Check if there's an edge from i to j
                if (!vis[j])
                {
                    if (dfs(j, adj, vis, i, V))
                    {
                        return true;
                    }
                }
                else if (j != parent)
                {
                    // If `j` is visited and not the parent of `i`, cycle is detected
                    return true;
                }
            }
        }

        return false;
    }

    bool isCyclic(int V, int **adj)
    {
        int *vis = new int[V];

        for (int i = 0; i < V; ++i)
        {
            vis[i] = 0;
        }

        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, -1, V))
                {
                    delete[] vis;
                    return true;
                }
            }
        }

        delete[] vis;
        return false;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Create adjacency matrix
    int **adj = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        adj[i] = new int[V];
        for (int j = 0; j < V; ++j)
        {
            adj[i][j] = 0; // Initialize all entries as 0
        }
    }

    cout << "Enter edges (start and end of each edge, 0-based indexing):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // Edge from u to v
        adj[v][u] = 1; // Edge from v to u (since undirected)
    }

    Solution sol;
    if (sol.isCyclic(V, adj))
    {
        cout << "Graph contains a cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle" << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i)
    {
        delete[] adj[i];
    }
    delete[] adj;

    return 0;
}
