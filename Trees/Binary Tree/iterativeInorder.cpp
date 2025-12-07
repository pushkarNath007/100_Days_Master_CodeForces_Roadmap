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

vector<int> iterativeInOrder(node *root)
{
    vector<int> ans;
    stack<node *> s1;
    // s1.push(root);
    node *tracknode = root;
    while (!s1.empty() || tracknode!=NULL)
    {
        if (tracknode != NULL)
        {
            s1.push(tracknode);
            tracknode = tracknode->left;
        }
        else
        {
            tracknode = s1.top();
            s1.pop();
            ans.push_back(tracknode->data);
            tracknode = tracknode->right;
            // at the end it will go to infinite loop 
            // when it will pop last right node with 
            // will again go to its right
        }
    }
    return ans;
}
int main()
{
    node *root = buildTree();
    vector<int> ans = iterativeInOrder(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}