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

void iterativePreOrder(node *root)
{
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        node *top = s.top();
        s.pop();
        cout << top->data << " ";
        if (top->right != NULL)
            s.push(top->right);
        if (top->left != NULL)
            s.push(top->left);
    }
}
int main()
{
    node *root = buildTree();
    iterativePreOrder(root);
    return 0;
}