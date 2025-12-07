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
    Node*root=new Node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
int maxWidth(Node*root){
    if(root==NULL) return 0;
    queue<pair<Node*,int>>q;
    int maxians=1;
    q.push(make_pair(root,1));
    while(!q.empty()){
        int size=q.size();
        int count=0,mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<size;i++){
            pair<Node *, int> temp=q.front();
            q.pop();
            Node*node=temp.first;
            int x=temp.second;
            if(node->left){
                q.push({node->left,2*x});
                mini=min(2*x,mini);
                maxi=max(2*x,maxi);
            }
            if(node->right){
                q.push({node->right,2*x+1});
                mini = min(2 * x+1, mini);
                maxi = max(2 * x+1, maxi);
            }
        }
        count=maxi-mini+1;
        maxians=max(count,maxians);
    }
    return maxians;
}
int main(){
   Node*root=buildTree();
    cout<<maxWidth(root);
   return 0; 
}