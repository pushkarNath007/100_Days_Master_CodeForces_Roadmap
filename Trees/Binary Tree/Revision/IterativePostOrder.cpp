#include <bits/stdc++.h>
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

vector<int> PostOrderIterative(node *root)
{
    stack<node *> s1;
    s1.push(root);
    node *pointer = root->left;
    vector<int> ans;
    while(!s1.empty()){
       if(pointer!=NULL) {
        s1.push(pointer);
        pointer=pointer->left;
       } 
       else{
            pointer=s1.top();
            // leaf node check
            if(pointer->right==NULL){
                s1.pop();
                ans.push_back(pointer->data);
                // node *temp = s1.top();
                while (!s1.empty() && s1.top()->right == pointer)
                {
                    // pointer = temp;
                    pointer=s1.top();
                    s1.pop();
                    ans.push_back(pointer->data);
                    // temp = s1.top();
                }
                if (!s1.empty())
                    pointer = s1.top()->right;
            }
            else pointer=pointer->right;
       }
    }
    return ans;
}
int main()
{
    node *root = buildTree();
    vector<int> ans = PostOrderIterative(root);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}