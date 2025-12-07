#include<bits/stdc++.h>
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
vector<vector<int>> zigZagTraversal(node*root){
    vector<vector<int>>ans;
    queue<node*>q;
    q.push(root);
    bool lvl=false;
    //  true means = reverse order inserting
    //  false = straight inserting
    while(!q.empty()){
        int size=q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++){
            node*ele=q.front();
            q.pop();
            (lvl)? temp[size-1-i]=ele->data :temp[i]=ele->data;
            if(ele->left) q.push(ele->left);
            if(ele->right) q.push(ele->right);
        }
        lvl=!lvl;
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    node*root=buildTree();
    vector<vector<int>>ans=zigZagTraversal(root);
    for(auto it:ans){
        for(auto ip:it) cout<<ip<<" ";
        cout<<endl;
    }
   return 0; 
}