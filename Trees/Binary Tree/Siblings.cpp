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

bool siblings(node *root, int x, int y)
{
    queue<node *> q;
    bool xcheck = false;
    bool ycheck = false;
    unordered_map<int, int> parent;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *val = q.front();
            q.pop();
            if (val->data == x)
            {
                xcheck = true;
            }
            else if (val->data == y)
            {
                ycheck = true;
            }
            if (val->left)
            {
                q.push(val->left);
                parent[val->left->data] = val->data;
            }
            if (val->right)
            {
                q.push(val->right);
                parent[val->right->data] = val->data;
            }
        }
        if (xcheck && ycheck)
        {
            if (parent[x] != parent[y])
                return true;
            else
                return false;
        }
        if (xcheck || ycheck)
            return false;
    }
    return false;
}
int main()
{
    node *root = buildTree();
    int x, y;
    cin >> x >> y;
    if (siblings(root, x, y))
        cout << "siblings";
    else
        cout<<"not siblings";
    return 0;
}