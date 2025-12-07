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
    if(data==-1) return NULL;
    Node* root=new Node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void btToLinkedListMorris(Node*root){
    Node*current=root;
    Node*start=NULL;
    while(current){
        if(current->left){
            Node*pre=current->left;
            while(pre->right && pre->right!=current) pre=pre->right;
            if(!pre->right){
                pre->right=current;
                Node*temp=current->left;
                current->left=NULL;
                current=temp;
            }
            else{
                if(current->right){
                    // find succesor 
                    Node*succ=current->right;
                    while(succ->left) succ=succ->left;
                    Node*temp=current->right;
                    current->right=succ;
                    current=temp;
                }
                else current=current->right;
            }  
        }
        else
        {
            if(!start) start=current;
            current = current->right;
        }
    }
    while(start){
        cout<<start->data<<" ";
        start=start->right;
    }

}
int main(){
   Node*root=buildTree();
   btToLinkedListMorris(root);
   return 0;
}