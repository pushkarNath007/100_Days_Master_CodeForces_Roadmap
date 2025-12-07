#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> addlist;
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

    void shortestPathDfs(T src, T dest)
    {
        unordered_map<T, bool> visited;
        stack<T> order;
        topologicalSortDFS(src, visited, order);
        order.push(src);
        shortesDfsHelper(order);
    }

    void topologicalSortDFS(T src, unordered_map<T, bool> &visited, stack<T> &order)
    {
        visited[src] = true;
        for (auto it : addlist[src])
        {
            if (!visited[it.first])
            {
                topologicalSortDFS(it.first, visited, order);
                order.push(it.first);
            }
        }
    }
    void shortesDfsHelper(stack<T> order)
    { //  0    5        3
        //   0- - -> 1 - - ->3
        //   |       ^    ^  ^
        //   |      2| 6 /  1|
        //   |  1    | /  6  |
        //    `- - ->2 - - ->4
        unordered_map<T, int> ans;
        stack<T> temp = order;
        while (!temp.empty())
        {
            ans[temp.top()] = INT_MAX;
            temp.pop();
        }
        ans[order.top()] = 0;
        while (!order.empty())
        {
            T var = order.top(); // 0
            // cout << var << endl;
            for (auto it : addlist[var])
            {
                int currTotalWeight = ans[var] + it.second;
                if (currTotalWeight < ans[it.first])
                {
                    ans[it.first] = currTotalWeight;
                }
                // cout << currTotalWeight << " ";
            }
            order.pop();
        }
        for (auto it : ans)
        {
            cout << it.first << " -> " << it.second << endl;
        }
    }
};

int main()
{
    graph<int> g1;
    g1.addValue(0, 1, 5, 0);
    g1.addValue(0, 2, 1, 0);
    g1.addValue(1, 3, 3, 0);
    g1.addValue(2, 1, 2, 0);
    g1.addValue(2, 3, 6, 0);
    g1.addValue(2, 4, 6, 0);
    g1.addValue(4, 3, 1, 0);

    g1.shortestPathDfs(0, 3);
    // g1.printing();
    return 0;
}