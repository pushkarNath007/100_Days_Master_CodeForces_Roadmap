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
    if (data == -1 || data == NULL)
        return NULL;
    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
void MorrisPreOrder(Node *root)
{
    Node *node = root;
    while (node)
    {
        if (node->left)
        {
            Node *lefty = node->left;
            while (lefty->right && lefty->right != node)
                lefty = lefty->right;
            if (!lefty->right)
            {
                lefty->right = node;
                cout << node->data << " ";
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        else
        {
            cout << node->data << " ";
            node = node->right;
        }
    }
}
void FlattenABinaryTree(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    FlattenABinaryTree(root->left);
    FlattenABinaryTree(root->right);

    if (root->left)
    {
        Node *temp = root->right;
        root->right = root->left;
        Node *check = root;
        while (check->right != NULL)
            check = check->right;
        check->right = temp;
        root->left = NULL;
    }
}
int main()
{
    Node *root = buildTree();
    FlattenABinaryTree(root);
    MorrisPreOrder(root);
    cout << endl;
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }
    return 0;
}