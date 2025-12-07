#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode *buildTree()
{
    int val;
    cin >> val;
    if (val == -1 || val == NULL)
        return NULL;
    TreeNode *root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
vector<int> iterativePostOrder(TreeNode *root)
{
    stack<TreeNode *> s1, s2;
    vector<int> ans;
    s1.push(root);
    while (!s1.empty())
    {
        TreeNode *top = s1.top();
        s1.pop();
        s2.push(top);
        if (top->left != NULL)
            s1.push(top->left);
        if (top->right != NULL)
            s1.push(top->right);
    }
    while (!s2.empty())
    {
        ans.push_back(s2.top()->val);
        s2.pop();
    }
    return ans;
}
int main()
{
    TreeNode *root = buildTree();
    vector<int> ans = iterativePostOrder(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}