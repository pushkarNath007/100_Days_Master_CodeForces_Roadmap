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

int lca(node*root, int x1,int x2){
    
    // if my both smaller function 
    // who explores root->left 
    // and if it finds both then it return lca
    // if one then it return that value
if(root == NULL) return NULL;
if(root->data==x1 || root->data==x2){
    return root->data;
}

  auto val1=lca(root->left,x1,x2);
  auto val2=lca(root->right,x1,x2);
  // if both found value means the value return is not lca 
  // since one value in left other in right
  // means this current node is lca
    if(val1 && val2) {
        return root->data;
    }
    if(!val1 && ! val2){
        return NULL;
    }
    if(val1) return val1;
    return val2;
}
 
int main()
{
    node *root = buildTree();
    int x1,x2;
    cin>>x1>>x2;
    cout<<lca(root,x1,x2);
    return 0;
}