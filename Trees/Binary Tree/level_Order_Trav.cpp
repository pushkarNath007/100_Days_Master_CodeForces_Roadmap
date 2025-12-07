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

node *buildNode()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node *tree = new node(data);
    tree->left = buildNode();
    tree->right = buildNode();
    return tree;
}
void levelOrderTraversal(node *&root)
{
    queue<node *> q;
    if (root == NULL)
        return;
    q.push(root);
    q.push(NULL);
    // q ->  1 NULL
    while (!q.empty())
    {
        // 1 null 2 6 null 3 4  5 7 null
        node *val = q.front();
        q.pop();
        if (q.empty())
        {
            return;
        }
        if (val == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << val->data << " ";
            // traverse its neighbour or child
            node *l = val->left;
            node *r = val->right;
            if (l != NULL)
            {
                // cout << " l " << l->data << " ";
                q.push(l);
            }
            if (r != NULL)
            {
                // cout << " r " << r->data << " ";
                q.push(r);
            }
        }
    }
    cout << " here " << q.empty();
}
int main()
{
    node *root = buildNode();
    levelOrderTraversal(root);
    return 0;
}