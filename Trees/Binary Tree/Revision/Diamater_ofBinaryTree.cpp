#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int diameter(TreeNode *root, int &maxi)
{

    if (root == NULL)
        return 0;
    int h1 = diameter(root->left, maxi);
    int h2 = diameter(root->right, maxi);
    if (h1 + h2 + 1 > maxi)
        maxi = h1 + h2 + 1;
    return max(h1, h2) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    // Write Your Code Here.
    int maxi = 0;
    int h = diameter(root, maxi);
    return maxi - 1;
}
TreeNode *buildTree()
{
    int data;
    cin >> data;
    if (data == -1 || data == NULL)
        return NULL;
    TreeNode *root = new TreeNode(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main()
{

    return 0;
}