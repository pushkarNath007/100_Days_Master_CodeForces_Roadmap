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
    if (val == -1)
        return NULL;
    TreeNode *root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void postOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}
void iterativePostOrder(TreeNode *root)
{
    stack<TreeNode *> s1;
    s1.push(root);
    TreeNode *node = root->left;

    while (!s1.empty())
    {
        if (node != NULL)
        {
            s1.push(node);
            node = node->left;
        }
        else
        {
            node = s1.top();
            // i want left leaf node not leftest node
            if (node->right == NULL)
            {
                s1.pop();
                cout << node->val << " ";
                while (!s1.empty() && s1.top()->right == node)
                {
                    node = s1.top();
                    s1.pop();
                    cout << node->val << " ";
                }
                if (!s1.empty())
                    node = s1.top()->right;
                // at last check will point to a node
                //  whose left child is node pointer
            }
            // if(!s1.empty()) node = s1.top()->right;
            // this is the error line because after getting
            // stack empty  we still give it to
            else
                node = node->right;
        }
    }
}
int main()
{
    TreeNode *root = buildTree();
    iterativePostOrder(root);
    // for (auto it : ans)
    //     cout << it << " ";
    // postOrderTraversal(root);
    return 0;
}