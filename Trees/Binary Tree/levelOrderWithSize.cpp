#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node *buildTree(){
    int data;
    cin>>data;
    if(data==-1 || data ==NULL) return NULL;
    node*root=new node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
vector<vector<int>> levelOrderUsingSize(node*root){
    vector<vector<int>>ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>temp;
        int size =q.size();
        for(int i=0;i<size;i++){
            node* top=q.front();
            q.pop();
            if(top->left!=NULL) q.push(top->left);
            if(top->right!=NULL) q.push(top->right);
            temp.push_back(top->data);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
   node*root=buildTree();

   vector<vector<int>>ans =levelOrderUsingSize(root);

   for(auto it:ans){
    for(auto col:it){
        cout<<col<<" ";
    }
    cout<<endl;
   }
   return 0; 
}