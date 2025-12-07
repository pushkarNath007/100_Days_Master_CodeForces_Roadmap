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

Node *buildCompleteBt(vector<int> &arr)
{
    if (!arr.size())
        return NULL;
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    Node *curr = q.front();
    q.pop();
    for (int i = 1; i < arr.size();)
    {
        if (!curr->left)
        {
            Node *temp = new Node(arr[i]);
            curr->left = temp;
            q.push(temp);
            i++;
        }
        else if (!curr->right)
        {
            Node *temp = new Node(arr[i]);
            curr->right = temp;
            q.push(temp);
            i++;
        }
        else{
            curr=q.front();
            q.pop();
        }
    }
    return root;
}
void MorrisInorder(Node*root){
    Node*curr=root;
    while(curr){
        if(curr->left){
            Node*pre=curr->left;
            while(pre->right && pre->right!=curr) pre=pre->right;
            if(!pre->right){
                pre->right=curr;
                curr = curr->left;
            }
            else{
                cout << curr->data << " ";
                pre->right=NULL;
                curr=curr->right;
            }
           
        }
        else{
           cout<<curr->data<<" ";
           curr=curr->right; 
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node*root=buildCompleteBt(arr);
    MorrisInorder(root);
    return 0;
}