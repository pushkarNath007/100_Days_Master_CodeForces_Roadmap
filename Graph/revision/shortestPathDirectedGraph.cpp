#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> addlist;
    void addValue(T u, T v, int w, int d)
    {
        addlist[u].push_back({v, w});
        if (d)
            addlist[v].push_back({u, w});
    }
    void printing()
    {
        for (auto it : addlist)
        {
            cout << it.first << " -> { ";
            for (auto nbr : it.second)
            {
                cout << "{" << nbr.first << ", " << nbr.second << " } ";
            }
            cout << "}" << endl;
        }
    }
    queue<int> topologicalSortBfs(int n)
    {
        queue<int> ans;
        //  values from 0 to n
        // first calculate indegree
        unordered_map<T, int> indegree;
        for (auto it : addlist)
        {
            for (auto nbr : it.second)
            {
                indegree[nbr.first]++;
            }
        }
        queue<T> q;
        for (int i = 0; i <= n; i++)
        {
            if (!indegree[i])
                q.push(i);
        }
        while (!q.empty())
        {
            T temp = q.front();
            q.pop();
            ans.push(temp);
            // cout << temp << " ";
            for (auto nbr : addlist[temp])
            {
                // listof pairs { {node,w},{node,w}}
                indegree[nbr.first]--;
                if (!indegree[nbr.first])
                    q.push(nbr.first);
            }
        }
        return ans;
    }
    vector<int> shortestPath(int n, int src)
    {
        vector<int> ans(n + 1, INT_MAX);
        queue<int> topoOrder = topologicalSortBfs(n);
        // root value has 0 since source and dest are same
        ans[src] = 0;
        // destination depend upon source
        // cout << ans[topoOrder.front()] << endl;
        while (!topoOrder.empty())
        {
            int temp = topoOrder.front();
            topoOrder.pop();
            for (auto nbr : addlist[temp])
            {
                // only node depended  from src 
                if (ans[temp] != INT_MAX)
                    ans[nbr.first] = min(ans[nbr.first], ans[temp] + nbr.second);
            }
        }
        return ans;
    }
};
int main()
{
    graph<int> g1;
    g1.addValue(0, 1, 5, 0);
    g1.addValue(0, 2, 3, 0);
    g1.addValue(1, 2, 2, 0);
    g1.addValue(1, 3, 6, 0);
    g1.addValue(2, 3, 7, 0);
    g1.addValue(2, 4, 4, 0);
    g1.addValue(2, 5, 2, 0);
    g1.addValue(3, 4, -1, 0);
    g1.addValue(4, 5, -2, 0);
    // g1.topologicalSortBfs(5);
    vector<int> ans = g1.shortestPath(5,1);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}