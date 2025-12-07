#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
Node*buildTree(){
    int data;
    cin>>data;
    if(data==-1) return NULL;
    Node*root=new Node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void longestZigZagTraversal(Node*root,vector<int>path,int &ans){
    // 1 =  left of parent  2 = right of parent
    if(root==NULL){
        int check = path.size() - 1;
         ans = max(ans,check);
        return;
    }
    if(!path.size()){
        longestZigZagTraversal(root->left,{1},ans);
        longestZigZagTraversal(root->right,{2},ans);
    }
    else if(path[path.size()-1]==2){
        path.push_back(1);
        longestZigZagTraversal(root->left,path,ans);
        longestZigZagTraversal(root->right,{2},ans);
    }
    else{
        path.push_back(2);
        longestZigZagTraversal(root->right,path,ans);
        longestZigZagTraversal(root->left, {1}, ans);
    }
}
void solve(Node*root){
    int ans=0;
    longestZigZagTraversal(root,{},ans);
    cout<<ans<<" ";
}
int main(){
   Node* root=buildTree();
    solve(root);
   return 0; 
}