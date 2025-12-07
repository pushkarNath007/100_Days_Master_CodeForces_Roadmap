#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
Node *buildTree()
{
    int data;
    cin >> data;
    if (data == -1 || data == NULL)
        return NULL;
    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void InorderSuccessor(Node *root, Node *&prev)
{
    // cout << root->data << " ";
    if (root == NULL)
        return;
    InorderSuccessor(root->left, prev);
    if ((prev) != NULL)
        (prev)->next = root;
    (prev) = root;
    InorderSuccessor(root->right, prev);
}
int main()
{
    Node *root = buildTree();
    Node *prev = NULL;
    InorderSuccessor(root, prev);
    Node *leftest = root;
    while (leftest->left != NULL)
    {
        leftest = leftest->left;
    }
    Node *start = leftest;
    while (start != NULL)
    {
        cout << start->data << " ";
        start = start->next;
    }
    return 0;
}