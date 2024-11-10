// There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
// There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
// of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
// value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
// the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
// distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
// It is ok if you wont use any warmhole.

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Vertex
{
 public:
    int x, y;
    Vertex(int x, int y) : x(x), y(y) {}
};

int distance(Vertex src, Vertex dest)
{
    return abs(src.x - dest.x) + abs(src.y - dest.y);
}

int ans = INT_MAX; // This stores the minimum distance

// This is a DFS function to find the minimum distance
void getMinDistance(const vector<vector<int>> &graph, int cur_vertex, int fin_vertex, vector<bool> &visited, int cur_dist)
{
    if (cur_vertex == fin_vertex)
    {
        ans = min(ans, cur_dist);
        return;
    }
    if (visited[cur_vertex])
        return;
    visited[cur_vertex] = true;

    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[cur_vertex][i] != -1)
        { // Only proceed if there's an edge (distance > -1)
            getMinDistance(graph, i, fin_vertex, visited, cur_dist + graph[cur_vertex][i]);
        }
    }

    visited[cur_vertex] = false;
}

int main()
{
    int sx, sy;
    cin >> sx >> sy;

    vector<Vertex> vertexList;
    vertexList.push_back(Vertex(sx, sy));

    int dx, dy;
    cin >> dx >> dy;
    Vertex dest_node(dx, dy);

    int num_holes;
    cin >> num_holes;

    int graphSize = num_holes * 2 + 2;
    vector<vector<int>> graph(graphSize, vector<int>(graphSize, -1));

    int graphIndex = 1;
    for (int i = 0; i < num_holes; i++)
    {
        int x1, y1, x2, y2, dist;
        cin >> x1 >> y1;
        Vertex hole_start(x1, y1);
        vertexList.push_back(hole_start);

        cin >> x2 >> y2;
        Vertex hole_end(x2, y2);
        vertexList.push_back(hole_end);

        cin >> dist;

        graph[graphIndex][graphIndex + 1] = graph[graphIndex + 1][graphIndex] = dist;
        graphIndex += 2;
    }

    vertexList.push_back(dest_node);

    // Initialize the distances from source to all other vertices and from destination to all other vertices
    for (int i = 0; i < graphSize; i++)
    {
        graph[0][i] = distance(vertexList[0], vertexList[i]);
        graph[graphSize - 1][i] = distance(vertexList[graphSize - 1], vertexList[i]);
    }

    // Fill the adjacency matrix for the wormholes
    for (int i = 1; i < graphSize - 1; i++)
    {
        for (int j = 0; j < graphSize; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else if (graph[i][j] == -1)
            {
                if (i % 2 == 1)
                {
                    graph[i][j] = graph[i][i + 1] + distance(vertexList[i + 1], vertexList[j]);
                }
                else
                {
                    graph[i][j] = graph[i][i - 1] + distance(vertexList[i - 1], vertexList[j]);
                }
            }
        }
    }

    graph[0][graphSize - 1] = graph[graphSize - 1][0] = distance(vertexList[0], vertexList[graphSize - 1]);

    vector<bool> visited(graphSize, false);

    getMinDistance(graph, 0, graphSize - 1, visited, 0);

    cout << "Minimum Distance: " << ans << endl;

    return 0;
}

// 0 0
// 100 100
// 3
// 1 2 120 120 2
// 4 5 120 100 3
// 6 8 102 102 4
// Minimum Distance: 22