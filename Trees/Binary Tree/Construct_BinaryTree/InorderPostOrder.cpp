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
void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
   
}
// void postOrderTraversal(Node *root)
// {
//     if (root == NULL)
//         return;
//     postOrderTraversal(root->left);
//     postOrderTraversal(root->right);
//     cout << root->data << " ";
// }

Node *building(vector<int> in, vector<int> post)
{
    if (!in.size() || !post.size())
        return NULL;
    int rootdata = post[post.size() - 1];
    Node *root = new Node(rootdata);
    int i = 0;
    for (i; i < in.size(); i++)
    {
        if (in[i] == rootdata)
            break;
    }

    vector<int> leftin;
    leftin.insert(leftin.begin(), in.begin(), in.begin() + i);

    vector<int> leftpost;
    leftpost.insert(leftpost.begin(), post.begin(), post.begin() + i);

    root->left = building(leftin, leftpost);

    vector<int> rightin;
    if (in.begin() + i + 1 < in.end())
        rightin.insert(rightin.begin(), in.begin() + i + 1, in.end());

    vector<int> rightpost;
    rightpost.insert(rightpost.begin(), post.begin() + i, post.end() - 1);

    root->right = building(rightin, rightpost);
    return root;
}

int main(){
    int n;
    cin >> n;
    // int in[n];
    // int pre[n];
    vector<int> in(n);
    vector<int> post(n);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    Node*root=building(in,post);
    PreOrder(root);
   return 0; 
}