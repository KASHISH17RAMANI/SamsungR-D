#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

public:
    unordered_map<T, list<pair<T, int>>> mp;

    void addEdge(T u, T v, int dist, bool bidir = true)
    {

        mp[u].push_back(make_pair(v, dist));
        if (bidir)
            mp[v].push_back(make_pair(u, dist));
    }
    void printadjList()
    {

        for (auto i : mp)
        {

            cout << i.first << "->";

            for (auto j : i.second)
            {

                cout << j.first << " " << j.second << " ";
            }
            cout << endl;
        }
    }
    void dijkastra(T src)
    {

        unordered_map<T, int> dist;

        for (auto j : mp)
        {
            dist[j.first] = INT_MAX;
        }

        set<pair<int, T>> s;

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {

            auto p = *(s.begin());

            T node = p.second;
            int nodeDist = p.first;

            s.erase(s.begin());

            for (auto childPair : mp[node])
            {

                if (nodeDist + childPair.second < dist[childPair.first])
                {

                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        for (auto d : dist)
        {
            cout << d.first << " is located at a distance of " << d.second << endl;
        }
    }
};

int main()
{

    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);
    // g.printadjList();
    g.dijkastra(1);

    return 0;
}