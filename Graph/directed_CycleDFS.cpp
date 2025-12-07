#include <bits/stdc++.h>
using namespace std;

// Your graphWithoutWeight template
template <typename T>
class graphWithoutWeight
{
public:
    unordered_map<T, list<T>> addlist;

    void addvalue(T u, T v, int direction)
    {
        // 1= undirectional
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

    void bfs(T src)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T temp = q.front();
            cout << temp << " ";
            q.pop();
            for (auto it : addlist[temp])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }

    void dfs(T src)
    {
        unordered_map<T, bool> visited;
        dfsHelper(src, visited);
    }

    void dfsHelper(T src, unordered_map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto it : addlist[src])
        {
            if (!visited[it])
            {
                dfsHelper(it, visited);
            }
        }
    }

    void printing()
    {
        for (auto node : addlist)
        {
            cout << node.first << " -> ";
            for (auto adj : node.second)
            {
                cout << adj << " ";
            }
            cout << endl;
        }
    }
};

// Your graph template with weight
template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> addlist;

    void addValue(T u, T v, int weight, int direction)
    {
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
                cout << "{ " << adj.first << ", " << adj.second << " } ";
            }
            cout << endl;
        }
    }
};
bool dfsHelper(int src, graphWithoutWeight<int> &g1, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsfunction)
{
    visited[src] = true;
    dfsfunction[src] = true;
    for (auto it : g1.addlist[src])
    {
        if (!visited[it])
        {
            bool ans = dfsHelper(it, g1, visited, dfsfunction);
            if (ans)
                return true;
            else
                dfsfunction[it] = false;
        }
        else
        {
            if (dfsfunction[it])
                return true;
        }
    }
    return false;
}
bool cyclicDFS(int src, graphWithoutWeight<int> &g1)
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsFunction;
    return dfsHelper(src, g1, visited, dfsFunction);
}

int main()
{
    graphWithoutWeight<int> g1;
    g1.addvalue(0, 1, 0);
    g1.addvalue(1, 2, 0);
    g1.addvalue(2, 3, 0);
    g1.addvalue(2, 4, 0);
    g1.addvalue(3, 4, 0);
    g1.addvalue(4, 2, 0);
    g1.addvalue(2, 5, 0);
    g1.addvalue(5, 7, 0);

    if(cyclicDFS(0, g1)) cout<<"cycle is present in direction graph";
    else  cout<<"cycle is not present in graph";
    return 0;
}