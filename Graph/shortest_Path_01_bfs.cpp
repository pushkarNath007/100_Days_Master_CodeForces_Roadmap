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
    vector<int> shortestPathBfs(int src, int dest)
    {
        // which ever  reach the destination first is the answer
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
            for (auto it : addlist[temp])
            {
                if (!visited[it])
                {
                    parent[it] = temp;
                    q.push(it);
                    visited[it] = true;
                }
            }
            if (parent[dest])
            {
                break;
            }
        }
        if (!parent[dest])
        {
            cout << "No route";
        }
        vector<int> ans;
        while (dest != -1)
        {

            ans.push_back(dest);
            dest = parent[dest];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
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

int main()
{
    // assume graph weight is 1
    graphWithoutWeight<int> g1;
    g1.addvalue(0, 1, 1);
    g1.addvalue(0, 2, 1);
    g1.addvalue(0, 3, 1);
    g1.addvalue(1, 4, 1);
    g1.addvalue(4, 5, 1);
    g1.addvalue(2, 5, 1);
    g1.addvalue(3, 6, 1);
    g1.addvalue(6, 5, 1);
    vector<int> ans = g1.shortestPathBfs(0, 5);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}