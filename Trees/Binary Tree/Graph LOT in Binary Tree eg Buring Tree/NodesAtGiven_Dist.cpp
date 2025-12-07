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
    if(data==-1 || data==NULL) return NULL;
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
void NodesAtGivenDistance(Node *root, int k, int target)
{
    // cout<<"here";
    unordered_map<Node *, Node *> parent = ListOfParents(root);
    // for(auto it:parent){
    //     if(it.second)
    //         cout<<it.second<<" parent of -> "<<it.first<<endl;
    // }
    int count=0;
    queue<Node*>q;
    unordered_map<Node*,bool> visited;
    Node*value=findNodeInOrder(root,target);
    if(!value) return ;
    q.push(value);
    visited[value]=true;
    while(!q.empty()){
        int size=q.size();
        if(count==k) break;
        for(int i=0;i<size && count<=k;i++){
            Node*node=q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
            }
            if(parent[node] && !visited[parent[node]]){
                // root parent is NULL thats why
                // parent has to be there condition also
                q.push(parent[node]);
                visited[parent[node]]=true;
            }
        }
        count++;
    
    }
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        q.pop();
    }
}
int main()
{
    Node *root = buildTree();
    int k, target;
    cin >> target >> k;
    NodesAtGivenDistance(root, k, target);
    return 0;
}