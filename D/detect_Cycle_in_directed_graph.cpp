#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int graph[101][101] = {0}; // adjacency matrix for the graph
int n;

bool dfs(int node, bool visited[], bool path_visited[])
{
    path_visited[node] = true; // mark the current node as visited in the path
    visited[node] = true;      // mark the node as fully visited

    // Check all possible neighbors
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i])
        { // If there is an edge from 'node' to 'i'
            if (!visited[i])
            { // If 'i' is not visited yet, do a DFS on 'i'
                if (dfs(i, visited, path_visited))
                {
                    return true; // Cycle found
                }
            }
            else if (path_visited[i])
            { // If 'i' is visited in the current path, a cycle is found
                return true;
            }
        }
    }
    path_visited[node] = false; // Backtrack, un mark the current node from the path
    return false;
}

bool check_cycle(bool visited[])
{
    bool path_visited[n] = {false}; // Track nodes in the current DFS path
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, visited, path_visited))
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
