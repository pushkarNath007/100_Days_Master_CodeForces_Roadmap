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
void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
   
}

Node *building(vector<int> inOrder, vector<int> LevelOrder)
{
    if(!inOrder.size() || !LevelOrder.size()) return NULL;
    int rootdata = LevelOrder[0];
    Node *root = new Node(rootdata);

    int i = 0;
    for (i;i<inOrder.size();i++){
        if(inOrder[i]==rootdata) break;
    }

    vector<int>leftin;
    unordered_map<int,bool>mpp1,mpp2;
    for(int j=0;j<i;j++){
        leftin.push_back(inOrder[j]);
        mpp1[inOrder[j]]=true;
    }

    vector<int>leftlevel;
    for(int j=0;j<LevelOrder.size();j++){
        if(mpp1.find(LevelOrder[j])!=mpp1.end()){
            leftlevel.push_back(LevelOrder[j]);
        }
    }

    root->left = building(leftin,leftlevel);

    vector<int>rightin;
    for(int j=i+1;j<inOrder.size();j++){
        rightin.push_back(inOrder[j]);
        mpp2[inOrder[j]]=true;
    }
    vector<int>rightlevel;
    for(int j=0;j<LevelOrder.size();j++){
        if(mpp2.find(LevelOrder[j])!=mpp2.end()){
            rightlevel.push_back(LevelOrder[j]);
        }
    }
    root->right=building(rightin,rightlevel);
    return root;
}
int main()
{
    int n;
    cin >> n;
    // int in[n];
    // int pre[n];
    vector<int> level(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> level[i];
    }
    Node *root = building(in, level);
    PreOrder(root);
    return 0;
}