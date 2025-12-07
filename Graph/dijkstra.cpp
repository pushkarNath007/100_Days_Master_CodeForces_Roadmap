#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> addlist;
    void addvalue(int u, int v, int w, int directed)
    {
        addlist[u].push_back({v, w});
        if (directed)
        {
            addlist[v].push_back({u, w});
        }
    }
    void printing()
    {
        for (auto it : addlist)
        {
            cout << it.first << " -> { ";
            for (auto nbr : it.second)
            {
                cout << "{ " << nbr.first << " , " << nbr.second << " } ";
            }
            cout << "}" << endl;
        }
    }
    void dijkstra(int src, int n)
    {
        set<pair<int, int>> s1;
        vector<int> ans(n, INT_MAX);
        ans[src] = 0;
        s1.insert(make_pair(0, src));

        while (!s1.empty())
        {
            //  set  sorted element automatically acc to first eleemnt
            auto element = *(s1.begin());
            // now element contain src pair
            int dist = element.first;
            int node = element.second;
            s1.erase(s1.begin());
            for (auto it : addlist[node])
            {
                int newDist = dist + it.second;
                if (newDist < ans[it.first])
                {

                    // now check if  this node dist is laready there in set
                    // and old dist will be same as ans dist too
                    auto check = s1.find(make_pair(ans[it.first], it.first));
                    // if found
                    if (check != s1.end())
                    {
                        // then remove
                        s1.erase(check);
                    }
                    // now insert
                    s1.insert(make_pair(newDist, it.first));
                    ans[it.first] = newDist;
                }
            }
        }
        // now we got the ans index
        for (auto it : ans)
            cout << it << " ";

        return;
    }
};
int main()
{
    graph<int> g1;
    g1.addvalue(2, 1, 5, 0);
    // g1.addvalue(6, 2, 5, 0);
    g1.addvalue(1, 3, 15, 0);
    // g1.addvalue(1, 3, 2, 0);
    // g1.addvalue(1, 4, 1, 0);
    g1.addvalue(2, 3, 6, 0);
    g1.addvalue(3, 4, 2, 0);
    // g1.addvalue(3, 5, 1, 0);
    // g1.addvalue(4, 5, 2, 0);

    // make sure n+1 to send because 1 =  1st index in ans array
    g1.dijkstra(2, 5 );
    // since 0th index is not there hence it will comtain INT_MAX value

    return 0;
}