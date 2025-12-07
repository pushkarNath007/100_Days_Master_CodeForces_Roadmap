#include <bits/stdc++.h>
using namespace std;

//  graph without weight
template <typename T>
class graphWithoutWeight
{
public:
    // property
    unordered_map<T, list<T>> addlist;

    // behaviour
    void addvalue(T u, T v, int direction)
    {
        // if direction is 0  unidirectional
        // if direction is 1  bidirectional
        if (direction)
        {
            addlist[u].push_back(v);
            addlist[v].push_back(u);
        }
        else
        {
            addlist[u].push_back(v);
        }
    }
    void printing()
    {
        for (auto node : addlist)
        {
            cout << node.first << " -> ";
            for (auto edge : node.second)
            {
                cout << edge << " , ";
            }
            cout << endl;
        }
    }
    void bfs(T src)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        q.push(src);
        cout << " bfs traversal " << endl;
        while (!q.empty())
        {
            T val = q.front();
            q.pop();
            cout << val << " ";
            visited[val] = true;
            for (auto it : addlist[val])
            {
                if (!visited[it])
                {
                    q.push(it);
                }
            }
        }
    }
    unordered_map<T, bool> visited;
    void dfs(T src)
    {
        // cout << endl
        //      << "dfs  traversal " << endl;
        cout << src << " ";
        visited[src] = true;
        for (auto it : addlist[src])
        {
            if (!visited[it])
                dfs(it);
        }
    }
};

// graph with weight
template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> addlist;

    void addValue(T u, T v, int weight, int direction)
    {
        // direction =0  unidirected
        // direction =1   directed =  birectional
        addlist[u].push_back({v, weight});
        if (direction)
        {
            addlist[v].push_back({u, weight});
        }
    }
    void printing()
    {
        for (auto node : addlist)
        {
            cout << node.first << " -> ";
            for (auto adj : node.second)
            {
                cout << "{ " << adj.first << " ," << adj.second << " }";
            }
            cout << endl;
        }
    }
};

int main()
{
    graphWithoutWeight<int> b1;
    b1.addvalue(0, 1, 0);
    b1.addvalue(0, 2, 0);
    b1.addvalue(1, 3, 0);
    b1.addvalue(2, 4, 0);

    b1.printing();
    b1.bfs(0);
    cout << endl;
    b1.dfs(0);
    graph<char> b2;
    b2.addValue('a', 'b', 8, 1);
    b2.addValue('b', 'c', 5, 1);
    b2.addValue('a', 'c', 6, 0);
    // b2.printing();
    return 0;
}