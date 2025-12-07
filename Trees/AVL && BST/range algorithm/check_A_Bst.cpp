#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1) return NULL;
    Node*root=new Node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
bool checkBst(Node*root, int l, int r){
    if(root==NULL) return true;
    if(root->data<l || root->data>r) return false;
    bool ans=checkBst(root->left,l,root->data);
    if(!ans) return false;
    ans=checkBst(root->right,root->data,r);
    if(!ans) return false;
    return true;
}
int main()
{
    Node*root=buildTree();
    if(checkBst(root,INT_MIN,INT_MAX)){
        cout<<"it is a BST";
    }
    else cout<<"it is not a BST";
    return 0;
}