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

int checkBlance(node*root, bool &ans){

// base condition
    if(root== NULL) return 0;
 // one step and smaller function repeat it and return all path ans
  int h1=  checkBlance(root->left, ans);
  int h2=  checkBlance(root->right, ans);
    if(abs(h1-h2)>1) ans=false;

    return max(h1,h2)+1;
}
bool balanceTree(node*root){
    bool ans=true;
    int h1=checkBlance(root, ans);
    return ans;
}
int main()
{
    node *root = buildTree();
    if(balanceTree(root)) cout<<"Balance";
    else cout<<"Not Balance";
    return 0;
}