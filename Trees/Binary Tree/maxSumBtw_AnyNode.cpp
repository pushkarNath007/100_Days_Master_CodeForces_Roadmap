#include <bits/stdc++.h>
using namespace std;

int maxi = INT_MIN;
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

int maxSum(node *root)
{
    if (root == NULL)
        return 0;
    int left = maxSum(root->left);
    int right = maxSum(root->right);
    int bothmax = max(left, right);
    int totalmax = max(bothmax + root->data, left + right + root->data);
    totalmax = max(totalmax, root->data);
    maxi = max(totalmax, maxi);

    return max(bothmax + root->data, root->data);
}
int main()
{
    node *root = buildTree();
    int l = maxSum(root);
    cout << maxi << " ";
    return 0;
}