#include<bits/stdc++.h>
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

int diameter(node*root, int&ans){
    if(root==NULL) return 0;
    int h1=diameter(root->left,ans);
    int h2=diameter(root->right,ans);
    if(h1+h2+1 >ans) ans=h1+h2+1;
    return max(h1,h2)+1;
}
int DiameterOfBinaryTree(node*root){
    int ans=0;
    int temp=diameter(root,ans);
    // length of path == total edge 
    // total edge =  total node-1
    return ans-1;
}
int main(){
   node* root=buildTree();
    cout<<DiameterOfBinaryTree(root);
   return 0; 
}