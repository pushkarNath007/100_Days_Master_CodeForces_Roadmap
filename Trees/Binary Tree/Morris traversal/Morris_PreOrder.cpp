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

    Node *current = root;
    while (current)
    {
        if(current->left){
            // find predecessor
            Node*pre=current->left;
            while(pre->right && pre->right!=current) pre=pre->right;

            if(!pre->right){
                // means movement is up to down
                cout<<current->data<<" ";
                pre->right=current;
                current=current->left;
            }
            else{
                // means movement is down to up  
                current=current->right;
            }
        }
        else{
            // no left means last value before moving up
            cout<<current->data<<" ";
            current=current->right;
        }
    }
}
int main()
{
    Node *root = buildTree();
    MorrisPreOrder(root);
    return 0;
}