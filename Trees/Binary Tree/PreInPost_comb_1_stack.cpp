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
node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node*root=new node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}

void iterative_PRE_IN_POST_inOneStackTogether(node*root){
    stack<pair<node*, int>>s1;
    s1.push(make_pair(root,1));
    vector<int>pre,post,in;
    while(!s1.empty()){
        auto val=s1.top();
        if(val.second==1){
           s1.pop();
           node*treenode=val.first;
            pre.push_back(treenode->data);
            val.second++;
            s1.push(val);
            if(treenode->left!=NULL) s1.push(make_pair(treenode->left,1));
        }
        else if(val.second==2){
            s1.pop();
            node*treenode=val.first;
            in.push_back(treenode->data);
            val.second++;
            s1.push(val);
            if(treenode->right!=NULL) s1.push({treenode->right,1});
        }
        else{
            s1.pop();
            node *treenode = val.first;
            post.push_back(treenode->data);
        }
    }
    cout<<"pre -> ";
    for(auto it:pre){
        cout<<it<<" ";
    }
    cout<<endl<<"in -> ";
    for(auto it:in){
        cout<<it<<" ";
    }
    cout<<endl<<"post -> ";
    for(auto it:post){
        cout<<it<<" ";
    }

}
int main(){
   node*root=buildTree();
   iterative_PRE_IN_POST_inOneStackTogether(root);
    return 0;
}