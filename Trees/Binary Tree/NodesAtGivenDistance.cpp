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

unordered_map<Node *, Node *> findParent(Node *root)
{

    unordered_map<Node *, Node *> mpp;
    queue<Node *> q;
    q.push(root);
    mpp[root] = NULL;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
            mpp[temp->left] = temp;
            // cout << mpp[temp->left] << " ";
        }
        if (temp->right)
        {
            q.push(temp->right);
            mpp[temp->right] = temp;
            // cout << mpp[temp->right] << " ";
        }
    }
    return mpp;
}
Node *findNodeInorder(Node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    Node *var = findNodeInorder(root->left, target);
    if (var)
    {
        // if var is not null
        return var;
    }
    var = findNodeInorder(root->right, target);
    if (var)
        return var;
    return NULL;
}
vector<int> KDistanceNodes(Node *root, int target, int k)
{ //  CODE START HERE -

    // first clculate the parent of current nodes as to move above also
    unordered_map<Node *, Node *> parent = findParent(root);
    // for(auto it:parent){
    //     if(it.second) cout<<it.first->data<<" -> "<<it.second->data<<endl<<endl;
    // }
    // now every nove will move  left right parent at level 1 = dist 1
    //   then these child will move next level == dist =2

    // so in simple take it as undirectional graph level order with k
    queue<Node *> q;
    unordered_map<Node *, bool> visited;
    // finding our target node
    Node *node = findNodeInorder(root, target);
    // cout << node->data << endl;
    if (!node)
        return {};

    // // now lot to all its neighbour with k leve;
    q.push(node);
    visited[node] = true;
    int count = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (count == k)
        {
            break;
        }
        for (int i = 0; i < size && count <= k; i++)
        {
            node = q.front();
            // cout << node->data << " count = " << count << endl
            //      << endl;
            q.pop();
            if (node->left && !visited[node->left])
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right && !visited[node->right])
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            if (parent[node] && !visited[parent[node]])
            {
                q.push(parent[node]);
                visited[parent[node]] = true;
            }
        }
        count++;
    }
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
    // return {};
}

int main()
{
    Node *root = buildTree();
    int target, k;
    cin >> target >> k;
    vector<int> ans = KDistanceNodes(root, target, k);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}