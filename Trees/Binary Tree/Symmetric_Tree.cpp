#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // parametric construction
    node(int data)
    {
        // this point to current class so *this.data
        this->data = data;
        this->left = NULL;
        right = NULL;
    }
};

node *buildNode()
{
    int data;
    cout << "Enter the value of node ";
    cin >> data;
    if (data == -1)
        return NULL;
    node *tree = new node(data);
    cout << "left node -> " << data << " value insert " << endl;
    tree->left = buildNode();
    cout << "right node -> " << data << " value insert " << endl;
    tree->right = buildNode();
    return tree;
}
bool same(node *p, node *q)
{
    // cout << "p-> " << p->data << " , q->data " << q->data << endl;

    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL || p->data != q->data)
    {
        // cout << "p == NULL || q == NULL " << p->data << " , q->data " << q->data << endl;
        return false;
    }
    return (same(p->left, q->right)) && (same(p->right, q->left));
}
bool isSymmetric(node *root)
{
    node *p = root->left;
    node *q = root->right;
    return same(p, q);
}
int main()
{
    node *root = NULL;
    root = buildNode();
    if (isSymmetric(root))
        cout << true;
    else
        cout << false;
    return 0;
}