#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(){
    int data;
    cin>>data;
    if(data==-1 || data ==NULL) return NULL;
    Node*root=new Node(data);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}
pair<int,int> nonAdjSum(Node*root, int &maxi){
    if(root==NULL) return {0,0};
    pair <int,int> leftsum=nonAdjSum(root->left,maxi);
    // <sum inc child, sum exc child>
    pair<int,int>rightsum = nonAdjSum(root->right,maxi);
    // two condition 
    // 1st include current node
    int incCurrent=leftsum.second+rightsum.second+root->data;

    int excCurrent= max(leftsum.first,leftsum.second)+max(rightsum.first,rightsum.second);
    maxi=max(maxi,max(incCurrent,excCurrent));
    return {incCurrent,excCurrent};
}

int NonAdjSumCalculator(Node*root){
    int maxi=INT_MIN;
    pair<int,int>ans=nonAdjSum(root,maxi);
    return maxi;
}
int main(){
   Node*root=buildTree();
   cout << NonAdjSumCalculator(root);
    return 0;
}