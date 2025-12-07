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

pair<int, int> sumOfLongestPath(node *root, int sum, int lvl)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> left = sumOfLongestPath(root->left, sum, lvl);
    pair<int, int> right = sumOfLongestPath(root->right, sum, lvl);
    if (left.second > right.second)
    {
        left.second++;
        left.first = left.first + root->data;
        return left;
    }
    else if (left.second < right.second)
    {
        right.second++;
        right.first = right.first + root->data;
        return right;
    }
    else if (left.first >= right.first)
    {
        left.second++;
        left.first = left.first + root->data;
        return left;
    }
    right.second++;
    right.first = right.first + root->data;
    return right;
}
void longestPathCalculator(node *root)
{
    pair<int, int> ans = sumOfLongestPath(root, 0, 0);
    cout << ans.first << " -> level -> " << ans.second << " ";
}
int main()
{
    node *root = buildTree();
    longestPathCalculator(root);
    return 0;
}