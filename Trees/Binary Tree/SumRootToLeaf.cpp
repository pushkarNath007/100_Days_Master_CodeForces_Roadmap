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

void MaxSum(node*root, pair<int,int>path, int & ans,int &maxh){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        path.second++;
        path.first+=root->data;

        if(path.second>=maxh){
            maxh=path.second;
            ans=path.first;
        }
        return;
    }
        path.first=path.first+root->data;
        path.second++;
        MaxSum(root->left,path,ans,maxh);
        MaxSum(root->right,path,ans,maxh);
        return;
}

int main()
{
    node *root = buildTree();
    pair<int,int>temp;
    temp.first=0;
    temp.second=0;
    int ans=0;
    int maxh=0;
    MaxSum(root,temp,ans,maxh);
    cout<<ans<<" ";
    return 0;
}