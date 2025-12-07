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

Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1 || data==NULL) return NULL;
    Node*root=new Node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

int helper(Node*root,int & mini){
    // 0 -> it required a camera
    // 1 -> it has a camera
    // 2 -> it is covered in its child camera
    if(root==NULL) return 2;
    if(root->left==NULL && root->right==NULL) return 0;
    int check1=helper(root->left,mini);
    int check2=helper(root->right,mini);
    if(!check1 || !check2){
        // means if any of its child required a camera 
        // parent will install a camera on itself
        mini++;
        return 1;
    }
    // now its child dont have a camera conditions 

    if(check1==1 || check2 ==1){
        // if any of its child has a camera root dont need it then
        return 2;
    }
    // now if both of its child are covered
    // then current node required a camera
    return 0;
}
int minCamera(Node*root){
    int mini=0;
    int check= helper(root,mini);
    if(!check) mini++;
    return mini;
}

int main(){
   Node*root=buildTree();
    cout<<minCamera(root);
   return 0; 
}