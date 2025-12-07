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
pair<bool, vector<int>> path(node *root, int target)
{
   // cout << root->data << endl;
   pair<bool, vector<int>> ans;

   if (root == NULL)
   {
      ans.first = false;
      return ans;
   }
   if (root->data == target)
   {
      ans.first = true;
      ans.second.push_back(root->data);
      return ans;
   }
   pair<bool, vector<int>> temp = path(root->left, target);
   // cout <<"left side "<< root->data << " -> first = ";
   // cout << temp.first << " array value -> ";
   // for (auto it : temp.second)
   //    cout << it << " ";
   // cout << endl
   //      << endl;
   if (temp.first)
   {
      ans.first = temp.first;
      ans.second.push_back(root->data);
      ans.second.insert(ans.second.end(), temp.second.begin(), temp.second.end());
      return ans;
   }

   temp = path(root->right, target);
   // cout <<"right side "<< root->data << " -> first = ";
   // cout << temp.first << " array value -> ";
   // for (auto it : temp.second)
   //    cout << it << " ";
   // cout << endl
   //      << endl;
   if (temp.first)
   {
      ans.first = temp.first;
      ans.second.push_back(root->data);
      ans.second.insert(ans.second.end(), temp.second.begin(), temp.second.end());
      return ans;
   }
   // if both route doesnt reach destination
   // then this node wont be included either
   ans.first = false;
   return ans;
}
int main()
{
   node *root = buildTree();
   int target;
   cin >> target;
   pair<bool, vector<int>> ans = path(root, target);
   for (auto it : ans.second)
      cout << it << " ";
   return 0;
}