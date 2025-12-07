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
unordered_map<Node *, Node *> parentNode(Node *root)
{
    queue<Node *> q;
    unordered_map<Node *, Node *> parent;
    q.push(root);
    parent[root] = NULL;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
            parent[temp->left] = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            parent[temp->right] = temp;
        }
    }
    return parent;
}
Node *FindInorder(Node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    Node *ans = FindInorder(root->left, target);
    if (ans)
    {
        return ans;
    }
    ans = FindInorder(root->right, target);
    if (ans)
    {
        return ans;
    }
    // if target not found
    return NULL;
}
int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> parent = parentNode(root);
    // for (auto it : parent)
    // {
    //     if (it.second)
    //         cout << it.first->data << " -> " << it.second->data << endl;
    // }
    Node *node = FindInorder(root, target);
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(node);
    visited[node] = true;
    int count = -1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            //   cout<<temp->data<<" count= "<<count<<endl;
            q.pop();
            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if (parent[temp] && !visited[parent[temp]])
            {
                q.push(parent[temp]);
                visited[parent[temp]] = true;
            }
        }
        count++;
    }
    return count;
}
int main(){
   Node*root=buildTree();
   cout << minTime(root,8);
    return 0;
}