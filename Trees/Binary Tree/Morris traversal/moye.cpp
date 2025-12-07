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
                pre->right = current;
                current = current->left;
            }
            else
            {
                // means pre is leaf node
                cout<< pre->data <<" ";
                // now remove all rights
                Node *temp = current->left;
                // while predecessor is not left of current
                while (temp != pre)
                {
                    if (temp->right == pre)
                    {
                       cout<<temp->data<<" ";
                        pre = temp;
                        temp = current->left;
                    }
                    else
                        temp = temp->right;
                }
                // means   current is last node at right side of root
                //  eg      () <- current  last node at right sides of root
                //         /
                //       () predecessor
                current->left = NULL;
                if (!current->right)
                {
                    cout<<current->data<<" ";
                    Node *temp = root;
                    while (temp!=current)
                    {
                        if (temp->right == current)
                        {
                            cout<<temp->data<<" ";
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
            if (!current->right)
            {
               cout<<current->data<<" ";
                Node *temp = root;
                while (temp)
                {
                    if (temp->right == current)
                    {
                        cout<<temp->data<<" ";
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