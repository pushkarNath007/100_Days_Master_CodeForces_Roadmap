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

bool cyclicBfs(int src, graphWithoutWeight<int> &b1)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto it : b1.addlist[temp])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
                parent[it] = temp;
            }
            else
            {
                if (parent[temp] != it)
                    return true;
            }
        }
    }
    return false;
}
bool dfsHelper(int src, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, graphWithoutWeight<int> &b1)
{
    // b1.addvalue(4, 3, 0);
    // 0 - 1 -2
    //       / \
    //      4 - 3
    visited[src] = true;
    for (auto it : b1.addlist[src])
    {
        if (!visited[it])
        {
            parent[it] = src;
            bool ans = dfsHelper(it, visited, parent, b1);
            if (ans)
                return true;
        }
        else
        {
            // cout << src << endl;
            if (parent[src] != it)
                return true;
        }
    }
    return false;
}
bool cyclicDfs(int src, graphWithoutWeight<int> &b1)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    parent[src] = -1;
    return dfsHelper(src, visited, parent, b1);
}
int main()
{
    graphWithoutWeight<int> b1;
    b1.addvalue(0, 1, 0);
    b1.addvalue(1, 2, 0);
    b1.addvalue(2, 3, 0);
    b1.addvalue(2, 4, 0);
    b1.addvalue(4, 3, 0);
    // 0 -> 1 ->2
    //       _/ \_
    //      4 ->`   a  3

    // b1.printing();
    // b1.dfs(0);
    cout << cyclicBfs(0, b1) << endl;
    // cout << cyclicDfs(0, b1);
    return 0;

    // edit distance
}