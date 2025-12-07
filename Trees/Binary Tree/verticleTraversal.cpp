#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int data;
    cin >> data;
    if (data == -1 || data == NULL)
        return NULL;
    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
vector<int> verticleTraversal(node *root)
{
    //  xd      lvl node   map stored in soreted order
    //  xd : lvl node 
    map<int, multiset<pair<int,node*>>> mp;
    queue<pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        node *val = temp.first;
        int xd = temp.second.first;
        int lvl = temp.second.second;
        mp[xd].insert({lvl,val});
        q.pop();
        if (val->left)
            q.push({val->left, {xd - 1, lvl + 1}});
        if (val->right)
            q.push({val->right, {xd + 1, lvl + 1}});
    }
    vector<int> ans;
    for (auto it : mp)
    {
        // cout << it.first << " -> ";
        for (auto pt : it.second)
        {
        //     cout << pt.first << " -> " << pt.second->data << endl;
            ans.push_back(pt.second->data);
        }
        // cout << endl;
    }
    return ans;
}
int main()
{
    node *root = buildTree();
    vector<int> ans = verticleTraversal(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}