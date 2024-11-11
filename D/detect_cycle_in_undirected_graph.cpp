#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int graph[101][101] = {0}; // adjacency matrix for the graph
int n;

bool dfs(int node, bool visited[], int parent)
{
    visited[node] = true;      // mark the node as fully visited

    // Check all possible neighbors
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i])
        { // If there is an edge from 'node' to 'i'
            if (!visited[i])
            { // If 'i' is not visited yet, do a DFS on 'i'
                if (dfs(i, visited, node))
                {
                    return true; // Cycle found
                }
            }
            else if (parent != i)
            { // If 'i' is visited in the current path, a cycle is found
                return true;
            }
        }
    }
    return false;
}

bool check_cycle(bool visited[])
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, visited, -1))
            {
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle found
}

int main()
{
    cin >> n; // number of nodes
    int t;    // number of edges
    cin >> t;

    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1; // Add directed edge from x to y
    }

    bool visited[n] = {false};            // Track if a node is fully visited
    cout << check_cycle(visited) << endl; // Output 1 if there's a cycle, 0 otherwise

    return 0;
}


// 5 10
// 0 1
// 1 0
// 1 2 
// 2 1
// 1 4
// 4 1
// 4 3
// 3 4
// 2 3
// 3 2
// 1