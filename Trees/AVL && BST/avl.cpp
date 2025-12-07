#include<bits/stdc++.h>
using namespace std;
#define max(a,b)  (a>b)? a :b

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    int height;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
        height=1;
    }
};
// height of root;
// ques-> why this func ? 
// ans-> because root->left->height can create prob so
int height(Node*root){
    if(!root) return 0;
    return root->height;
}

// balance factor return function
int isBalance(Node*root){
    if(root==NULL) return 0;
    return abs(height(root->left)-height(root->right));
}

// RightRotate FUNCTION
Node * RightRotate(Node*root){
    Node*newroot=root->left;
    // left root old right saved in x
    Node*x=newroot->right;
    newroot->right=root;
    root->left=x;

    // now update new height
    root->height=max(height(root->left),height(root->right))+1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
    return newroot;
}

// leftRotate function
Node * leftRotate(Node*root){
    Node*newroot=root->right;
    Node*x=newroot->left;
    newroot->left=root;
    root->right=x;
    root->height = max(height(root->left), height(root->right)) + 1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
    return newroot;
}
// inserting a new node
Node *  insertNode(Node*root,int data){
    if(root==NULL){
        Node*child=new Node(data);
        return child;
    }
        if(data<root->data){
         root->left = insertNode(root->left,data);
        }
        else if(data>root->data){
            root->right = insertNode(root->right, data);
        }
        else{
            return root;
        }
        // after inserting 
        // updata height of the ancestors
        root->height= max(height(root->left),height(root->right))+1;

        // now check balanced height factor
        int balance=isBalance(root);

        //  balance is >1  && < -1 means not Balanced

        //  4 CONDITIONS ->
        // if() -> left side max case -> RR or LR
        // else if()-> right side max case ->LL OR RL

        if(balance>1 && height(root->left)>height(root->right)){
            // now ll and lr condition
            // RR or LR
            if(data<root->left->data){
                return RightRotate(root);
            }
            else if(data>root->left->data){
                root->left=leftRotate(root->left);
                return RightRotate(root);
            }
        }
        else if(balance>1 && height(root->right)>height(root->left)){
            //  LL OR RL
    
            if(data>root->right->data){
                return leftRotate(root);
            }
            else if(data<root->right->data){
                root->right=RightRotate(root->right);
                return leftRotate(root);
            }
        }
       
        return root;
}
Node * buildTree(){
    Node*root=NULL;
    int data;
    cin>>data;
    while(data!=-1){
       root= insertNode(root,data);
        cin>>data;
    }
    return root;
}
void Inorder(Node*root){
    if(root==NULL) return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    return;
}
int main(){
    Node *root = buildTree();

    /* Constructing tree given in
    the above figure */
    // root = insertNode(root, 10);
    // root = insertNode(root, 20);
    // root = insertNode(root, 30);
    // root = insertNode(root, 40);
    // root = insertNode(root, 50);
    // root = insertNode(root, 25);
    
    Inorder(root);
    return 0; 
}