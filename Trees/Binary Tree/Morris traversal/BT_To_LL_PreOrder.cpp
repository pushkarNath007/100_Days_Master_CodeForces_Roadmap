#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void btToLinkedListMorris(Node *root)
{
    Node *current = root;
    while (current)
    {
        if (current->left)
        {
            Node *pre = current->left;
            while(pre->right) pre=pre->right;
            pre->right=current->right;
            current->right=current->left;
            current->left=NULL;
            current=current->right;// current right is current left actually now
        }
        else
        {
            current = current->right;
        }
    }
    Node*start=root;
    while (start)
    {
        cout << start->data << " ";
        start = start->right;
    }
}
int main()
{
    Node *root = buildTree();
    btToLinkedListMorris(root);
    return 0;
}