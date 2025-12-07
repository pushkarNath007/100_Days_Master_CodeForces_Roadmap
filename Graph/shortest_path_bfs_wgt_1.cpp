#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, T>>> addlist;
    void addValue(T u, T v, int w, int directed)
    {
        addlist[u].push_back({v, w});
        if (directed)
        {
            // undirected
            addlist[v].push_back({u, w});
        }
    }
    void printing()
    {
        for (auto it : addlist)
        {
            cout << it.first << " -> ( ";
            for (auto nbr : it.second)
            {
                // it gets values {} of pair of list
                cout << "{ " << nbr.first << " , " << nbr.second << " } ";
            }
            cout << " ) " << endl;
        }
    }
    vector<T> shortestPathBfs(T src, T dest)
    {
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            T temp = q.front();
            q.pop();
            for (auto it : addlist[temp])
            {
                if (!visited[it.first])
                {
                    q.push(it.first);
                    visited[it.first] = true;
                    parent[it.first] = temp;
                }
            }
            if (parent[dest])
            {
                break;
            }
        }
        vector<T> ans;
        while (dest != -1)
        {
            ans.push_back(dest);
            dest = parent[dest];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    graph<int> g1;
    g1.addValue(0, 1, 2, 0);
    g1.addValue(0, 2, 2, 0);
    g1.addValue(0, 3, 3, 0);
    g1.addValue(1, 4, 6, 0);
    g1.addValue(2, 5, 2, 0);
    g1.addValue(3, 6, 6, 0);
    g1.addValue(4, 5, 8, 0);
    g1.addValue(6, 5, 1, 0);
    g1.addValue(5, 7, 7, 0);

    vector<int> ans = g1.shortestPathBfs(0, 5);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}