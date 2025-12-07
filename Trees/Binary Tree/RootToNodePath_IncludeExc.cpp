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

bool pathFindIncluded(node *root, vector<int> &ans, int target)
{
   if (root == NULL)
      return false;
   if (root->data == target)
   {
      ans.push_back(root->data);
      return true;
   }
   ans.push_back(root->data);
   bool check = pathFindIncluded(root->left, ans, target);
   if (check == true)
      return true;
   check = pathFindIncluded(root->right, ans, target);
   if (check == true)
      return true;
   ans.pop_back();
   return false;
}
void solve(node *root, int &target)
{
   vector<int> ans;
   bool check = pathFindIncluded(root, ans, target);
   for (auto it : ans)
      cout << it << " ";
   return;
}
int main()
{
   node *root = buildTree();
   int target;
   cin >> target;
   solve(root, target);
   return 0;
}