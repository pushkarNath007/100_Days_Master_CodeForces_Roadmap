#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next1)
    {
        this->data = data;
        next = next1;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node * buildList(vector<int>&arr){
    if(!arr.size()) return NULL;
    Node*head=new Node(arr[0]);
    Node*iter=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        iter->next=temp;
        iter=temp;
    }
    return head;
}
Node* DeleteNodeWithPosition(Node*head, int k){
    Node*prev=NULL;
    Node*iter=head;
    int cnt=1;
    while(iter){
        if(cnt==k){
            if(!prev){
                // k==1 condition where prev is NULL at start
                head=iter->next;
                free(iter);
                return head;
            }
            else{
               prev->next=iter->next;
               free(iter);
               return head; 
            }
        }
        prev=iter;
        iter=iter->next;
        cnt++;
    }
    return head;
}
void printing(Node*head){
    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node*head=buildList(arr);
    head=DeleteNodeWithPosition(head,k);
    printing(head);
    return 0;
}