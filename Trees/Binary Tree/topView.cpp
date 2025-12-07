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
vector<int> topView(node *root)
{
    map<int, map<int, node *>> mp;
    vector<int> ans;
    queue<pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *value = temp.first;
        int xd = temp.second.first;
        int lvl = temp.second.second;
        if (auto it = mp.find(xd); it == mp.end())
        {

            mp[xd][lvl] = value;
        }

        if (value->left)
            q.push({value->left, {xd - 1, lvl + 1}});
        if (value->right)
            q.push({value->right, {xd + 1, lvl + 1}});
    }
    for (auto it : mp)
    {
        for (auto np : it.second)
        {
            ans.push_back(np.second->data);
        }
    }
    return ans;
}
int main()
{
    node *root = buildTree();
    vector<int> ans = topView(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}