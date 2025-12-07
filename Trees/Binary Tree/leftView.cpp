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
    if (data == -1 || data == NULL)
        return NULL;
    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}
vector<int> leftView(node*root){
    queue<node*>q;
    q.push(root);
    vector<int>ans;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            node*val=q.front();
            if(i==0) ans.push_back(val->data);
            q.pop();
            if(val->left) q.push(val->left);
            if(val->right) q.push(val->right);
        }
    }
    return ans;
}
int main(){
    node *root = buildTree();
    vector<int> ans = leftView(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}