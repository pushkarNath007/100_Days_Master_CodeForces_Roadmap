#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;

   Node(int data)
   {
      this->data = data;
      left = NULL;
      right = NULL;
   }
};

Node *buildTree()
{
   int data;
   cin >> data;
   if (data == -1 || data == NULL)
      return NULL;
   Node *root = new Node(data);
   root->left = buildTree();
   root->right = buildTree();

   return root;
}
void MorrisInorder(Node*root){
  
      Node*current=root;
      while(current){
         if(current->left){
            // find its predecessor
            Node*pre=current->left;
            while(pre->right && pre->right!=current){
               pre=pre->right;
            }
            if(!pre->right){
               // if null means you are goint up to down and creating temporary link
               pre->right=current;
               current=current->left;
            }
            else{
               // if predeccesor is pointing to current(root) node mean
               // you are going up   means already printed left node
               // now print root and move right
               cout<<current->data<<" ";
               current=current->right;
            }  
         }
         else{
            // if current left is null 
            // means time to move up
            cout<<current->data<<" ";
            current=current->right;
         }
      }
      
}
int main(){
   Node*root=buildTree();
   MorrisInorder(root);
   return 0; 
}