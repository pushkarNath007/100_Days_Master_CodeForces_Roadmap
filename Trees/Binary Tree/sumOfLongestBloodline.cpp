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
    if (data == -1)
        return NULL;
    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void sumOfLongestBloodline(node *root, int h, int sum, int &maxh, int &ans)
{
    // cout << root->data << " " << sum << " " << h << " " << maxh << " " << ans << endl
    //      << endl;
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        h += 1;
        sum += root->data;
        if (h >= maxh)
        {
            maxh = h;
            ans = sum;
        }
        return;
    }

    sumOfLongestBloodline(root->left, h + 1, sum + root->data, maxh, ans);
   
    sumOfLongestBloodline(root->right, h + 1, sum + root->data, maxh, ans);
}
void solve(node *root)
{
    int ans = 0, h = 0, maxh = 0, sum = 0;
    sumOfLongestBloodline(root, h, sum, maxh, ans);
    cout << ans << " with  height -> " << maxh;
}
int main()
{
    node *root = buildTree();
    solve(root);
    return 0;
}