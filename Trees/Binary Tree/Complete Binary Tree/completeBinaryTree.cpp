#include <bits/stdc++.h>
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
    if (data == -1)
        return NULL;
    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
bool CompleteBinaryTree(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*node=q.front();
        q.pop();
        if(!node){
            while(!q.empty()&&q.front()==NULL) q.pop();
            if(q.empty()) return true;
            else return false;
        }
        else{
            if(node->left) q.push(node->left);
            else q.push(NULL);
            if(node->right) q.push(node->right);
            else q.push(NULL);
        }
    }
}
int main()
{
    Node *root = buildTree();
    if(CompleteBinaryTree(root)) cout<<"Complete Binary Tree";
    else cout<< "Not a Complete Binary Tree";
    return 0;
}