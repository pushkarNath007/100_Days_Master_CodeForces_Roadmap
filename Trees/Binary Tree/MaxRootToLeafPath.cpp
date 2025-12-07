#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
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

void maxPathFromRootToLeaf(node *root, vector<int> temp)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        temp.push_back(root->data);
        if (temp.size() > ans.size())
        {
            ans = temp;
        }
        return;
    }
    temp.push_back(root->data);
    maxPathFromRootToLeaf(root->left, temp);
    maxPathFromRootToLeaf(root->right, temp);
    // temp.pop_back();
    // you are doing call by value
    return;
}
int main()
{
    node *root = buildTree();
    vector<int> temp;
    maxPathFromRootToLeaf(root, temp);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}