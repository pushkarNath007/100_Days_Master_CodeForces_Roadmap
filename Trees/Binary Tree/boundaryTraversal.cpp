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
    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
vector<int> leftBoundaryWithoutLeaf(node *val, vector<int> &ans)
{
    
    node *root = val;
    while (root != NULL)
    {
        ans.push_back(root->data);
        if (root->left)
        {
            root = root->left;
        }
        else{
            if(root->right==NULL){
                ans.erase(ans.end()-1);
                break;
            }
            root=root->right;
        }
    }
    return ans;
}
bool leafNodePreorder(node*root,vector<int>&ans){
    if(root==NULL) return false;
    bool leftans=leafNodePreorder(root->left,ans);
    bool rightans=leafNodePreorder(root->right,ans);
    if(!leftans && !rightans){
        ans.push_back(root->data);
    }
    return true;
}
void rightNodeWithoutLeafIterative(node*root,vector<int>&ans){
    // it gets root->right as root at starting 
    node*val=root;
    stack<int>s1;
    while(val!=NULL){
        s1.push(val->data);
        if(val->right) val=val->right;
        else{
            // if val->right is NULL then
            // check if its a root node
            if(val->left==NULL){
                s1.pop();
                break;
            }
            // now if it comes here means left part is there
            val=val->left;
        }
    }
    while(!s1.empty()){
        ans.push_back(s1.top());
        s1.pop();
    }
}
vector<int> BoundaryTraversal(node*root){
    vector<int>ans;
    if(root==NULL) return ans;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return ans;
    }
    leftBoundaryWithoutLeaf(root,ans);
    leafNodePreorder(root,ans);
    rightNodeWithoutLeafIterative(root->right,ans);
    return ans;
}
int main()
{
    node *root = buildTree();
    
    // vector<int> ans = leftBoundaryWithoutLeaf(root);
    vector<int>ans=BoundaryTraversal(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}