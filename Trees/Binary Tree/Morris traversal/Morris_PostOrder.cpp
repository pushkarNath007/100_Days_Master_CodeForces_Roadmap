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
void MorrisPostOrder(Node *root)
{

    Node *current = root;
    while (current)
    {
        if (current->left)
        {
            // find predecessor
            Node *pre = current->left;
            while (pre->right && pre->right != current)
                pre = pre->right;

            if (!pre->right)
            {
                // if null
                // means going up to down
                pre->right = current;
                current = current->left;
            }
            else
            {
                // means pre is leaf node
                cout << pre->data << " ";
                // now loop to check whether its right
                // of its parent
                Node *temp = current->left;
                while (temp != pre)
                {
                    if (temp->right == pre)
                    {
                        cout << temp->data << " ";
                        pre = temp;
                        temp = current->left;
                    }
                    else
                        temp = temp->right;
                }
                current->left = NULL;
                if (!current->right)
                {
                    cout << (current->data) << " ";
                    Node *temp = root;
                    while (temp != current)
                    {
                        if (temp->right == current)
                        {
                            cout << (temp->data) << " ";
                            current = temp;
                            temp->right = NULL;
                            temp = root;
                        }
                        else
                            temp = temp->right;
                    }
                }
                current = current->right;
            }
        }
        else
        {
            // no current left check if its last nodeor
            // or 2nd last node (right node)
            if (!current->right)
            {
                cout << (current->data) << " ";
                Node *temp = root;
                while (temp)
                {
                    if (temp->right == current)
                    {
                        cout << (temp->data) << " ";
                        current = temp;
                        temp->right = NULL;
                        temp = root;
                    }
                    else
                        temp = temp->right;
                }
            }
            current = current->right;
        }
    }
}
int main()
{
    Node *root = buildTree();
    MorrisPostOrder(root);
    return 0;
}