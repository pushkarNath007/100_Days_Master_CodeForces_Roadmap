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
    if (data == -1 || data == NULL)
        return NULL;
    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
unordered_map<Node *, Node *> ListOfParents(Node *root)
{
    // cout << "here";
    unordered_map<Node *, Node *> parent;
    queue<Node *> q;
    q.push(root);
    parent[root] = NULL;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node->left)
        {
            q.push(node->left);
            parent[node->left] = node;
        }
        if (node->right)
        {
            q.push(node->right);
            parent[node->right] = node;
        }
    }
    return parent;
}
Node *findNodeInOrder(Node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    Node *ans = findNodeInOrder(root->left, target);
    if (ans)
    {
        return ans;
    }
    ans = findNodeInOrder(root->right, target);
    if (ans)
        return ans;
    return NULL;
}
void burningTree(Node*root,int target){
    unordered_map<Node*,Node*> parent=ListOfParents(root);

    Node*node=findNodeInOrder(root,target);
    if(!node) return ;
    int count=-1;
    // bcs when 1st level value got pop and 
    // 2nd level value got put
    // your answer should be -1 at that time

    queue<Node*>q;
    unordered_map<Node*,bool>visited;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node*value=q.front();
            q.pop();
            if(value->left && !visited[value->left]){
                q.push(value->left);
                visited[value->left]=true;
            }
            if(value->right && !visited[value->right]){
                q.push(value->right);
                visited[value->right]=true;
            }
            if(parent[value] && !visited[parent[value]]){
                q.push(parent[value]);
                visited[parent[value]]=true;
            }
        }
        count++;
    }

    cout<<count<<" ";
    return;
    
}
int main()
{
    Node *root = buildTree();
    int target;
    cin >> target;
    burningTree(root, target);
    return 0;
}