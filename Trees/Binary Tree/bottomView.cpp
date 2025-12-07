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
vector<int> bottomView(node *root)
{
    map<int, int> mp;
    queue<pair<int, node *>> q;
    q.push({0, root});
    vector<int> ans;
    while (!q.empty())
    {
        pair<int, node *> temp = q.front();
        q.pop();
        auto val = mp.find(temp.first);
        if (val != mp.end())
        {
            // if previous xd and its node values is present
            // erase it first
            mp.erase(val);
        }
        mp[temp.first] = temp.second->data;
        if (temp.second->left)
            q.push({temp.first - 1, temp.second->left});
        if (temp.second->right)
            q.push({temp.first + 1, temp.second->right});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
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

int main()
{
    node *root = buildTree();
    vector<int> ans = bottomView(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}