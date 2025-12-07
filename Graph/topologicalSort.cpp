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
    void topologicalSortDFS(int src)
    {
        stack<int> order;
        unordered_map<int, int> visited;
        topologicalHepler(src, order, visited);
        order.push(src);
        while (!order.empty())
        {
            cout << order.top() << " ";
            order.pop();
        }
    }
    void topologicalHepler(int src, stack<int> &order, unordered_map<int, int> &visited)
    {
        visited[src] = true;
        for (auto it : addlist[src])
        {
            if (!visited[it])
            {
                topologicalHepler(it, order, visited);
                order.push(it);
            }
        }
    }
    void topologicalBFS(int n)
    {
        unordered_map<int, int> indegree;
        queue<int> order;
        cout<<endl;
        // taking out all indegree
        for (auto it : addlist)
        {
            for (auto nbr : it.second)
            {
                indegree[nbr]++;
            }
        }
        // now storing all node with 0 degree in queue
        for (int i = 0; i <= n; i++)
        {
            if (indegree[i] == 0)
                order.push(i);
        }
        while (!order.empty())
        {
            int src = order.front();
            cout << src << " ";
            order.pop();
            for (auto it : addlist[src])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    order.push(it);
            }
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

int main()
{
    //   0- - -> 1 - - ->3
    //   |       ^    ^  ^
    //   |       |   /   |
    //   |       | /     |
    //    `- - ->2 - - ->4
    graphWithoutWeight<int> g1;
    g1.addvalue(0, 1, 0);
    g1.addvalue(0, 2, 0);
    g1.addvalue(2, 1, 0);
    g1.addvalue(1, 3, 0);
    g1.addvalue(2, 3, 0);
    g1.addvalue(2, 4, 0);
    g1.addvalue(4, 3, 0);
    
    g1.topologicalSortDFS(0);
    g1.topologicalBFS(4);
    return 0;
}