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
void PostOrder(Node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
// void postOrderTraversal(Node *root)
// {
//     if (root == NULL)
//         return;
//     postOrderTraversal(root->left);
//     postOrderTraversal(root->right);
//     cout << root->data << " ";
// }
void iterativePostOrder(Node *root)
{
    stack<Node *> s1;
    s1.push(root);
    Node *node = root->left;

    while (!s1.empty())
    {
        if (node != NULL)
        {
            s1.push(node);
            node = node->left;
        }
        else
        {
            node = s1.top();
            // i want left leaf node not leftest node
            if (node->right == NULL)
            {
                s1.pop();
                cout << node->data << " ";
                while (!s1.empty() && s1.top()->right == node)
                {
                    node = s1.top();
                    s1.pop();
                    cout << node->data << " ";
                }
                if (!s1.empty())
                    node = s1.top()->right;
                // at last check will point to a node
                //  whose left child is node pointer
            }
            // if(!s1.empty()) node = s1.top()->right;
            // this is the error line because after getting
            // stack empty  we still give it to
            else
                node = node->right;
        }
    }
}

Node * building(vector<int> pre, vector<int> in)
{
    if (pre.size() == 0 || in.size() == 0)
        return NULL;
    int rootdata = pre[0];
    Node *root = new Node(rootdata);
    // cout << " root = " << root->data << " ";
    int i = 0;
    for (i; i < in.size(); i++)
    {
        if (in[i] == rootdata)
            break;
    }
    vector<int> leftpre; // in case i==0  1 to 1+0  it will make empty array
    leftpre.insert(leftpre.begin(), pre.begin() + 1, pre.begin() + i + 1);

    //    cout<<endl<<" leftpre"<<" -> ";
    //    for(auto it:leftpre) cout<<it<<" ";

    vector<int> leftin;
    leftin.insert(leftin.begin(), in.begin(), in.begin() + i);

    // cout<<endl<<" leftin"<<" -> ";
    // for (auto it : leftin)
    //     cout << it << " ";

    root->left = building(leftpre, leftin);
    
    // if(root->left!=NULL) cout<<" root = "<<root->data<<" -> root->left = "<<root->left->data<<endl; 

    vector<int> rightpre;
    rightpre.insert(rightpre.begin(), pre.begin() + i + 1, pre.end());

    // cout<<endl<<"rightpre"<<" -> ";
    // for (auto it : rightpre)
    //     cout << it << " ";
    vector<int> rightin;
    rightin.insert(rightin.begin(), in.begin() + i + 1, in.end());
    // cout <<endl<<"rightin"<<" -> ";
    // for (auto it : rightin)
    //     cout << it << " ";
    root->right = building(rightpre, rightin);
    // if(root->right !=NULL)cout << " root = " << root->data << " -> root->right = " << root->right->data << endl;

    return root;
}
Node *buildingTree(int in[], int pre[], int n)
{
    vector<int> inarr(n);
    copy(in, in + n, inarr.begin());
    vector<int> prearr(n);
    copy(pre, pre + n, prearr.begin());
    return building(prearr,inarr);
}
int main()
{
    int n;
    cin >> n;
    int in[n];
    int pre[n];
    // vector<int> pre(n);
    // vector<int> in(n);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    Node *root = buildingTree(in,pre,n);
    // PostOrder(root);
    PostOrder(root);
    return 0;
}