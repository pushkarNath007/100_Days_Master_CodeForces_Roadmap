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
int minDepth(node *root)
{

    if (root == NULL)
        return 0;
    queue<node *> q;
    q.push(root);
    int level = 1;
    q.push(NULL);
    while (!q.empty())
    {
        //   q ->    3 null 9 20 null
        // level->   1  2
        node *top = q.front();
        q.pop();
        if (q.empty())
        {
            // cout <<"here" top->data << " ";
            return level;
        }
        if (top == NULL)
        {
            q.push(NULL);
            level++;
            // cout << "level -> " << level << endl;
        }
        else
        {
            node *l = top->left;
            node *r = top->right;
            if (l == NULL)
            {
                return level;
            }
            else
                q.push(l);

            if (r == NULL)
                return level;
            else
                q.push(r);
        }
    }
    return level;
}
int main()
{
    node *root = buildNode();
    cout << minDepth(root);
    return 0;
}