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

vector<int> InorderIterative(node *root)
{
    stack<node *> s1;
    node *pointer = root;
    vector<int> ans;
    while (!s1.empty() || pointer != NULL)
    {
        if (pointer!= NULL)
        {
            s1.push(pointer);
            pointer = pointer->left;
        }
        else
        {
            pointer = s1.top();
            s1.pop();
            ans.push_back(pointer->data);
            pointer = pointer->right;
        }
    }
    return ans;
}
int main()
{
    node *root = buildTree();
    vector<int> ans = InorderIterative(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}