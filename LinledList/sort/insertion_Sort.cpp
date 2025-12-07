#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node*buildList(){
    int data;
    cin>>data;
    if(data==-1) return NULL;
    Node*root=new Node(data);
    root->next=buildList();
    return root;
}
void printing(Node*head){
    cout<<"printing "<<endl;
    Node*iter=head;
    while(iter){
        cout<<iter->data<<" ";
        iter=iter->next;
    }
}
void insertion(Node *head, Node *val)
{
    Node *curr = head;
    while (curr->next && curr->next->data < val->data)
    {

        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = val;
    val->next = temp;
    // curr < val  ans curr->next > val
}
Node *insertionSort(struct Node *head)
{
    Node *curr = head->next;
    Node *reshead = head;
    reshead->next = NULL;
    //   Node*res=reshead;
    while (curr)
    {
        //  if(res->next) res->next=NULL;
        Node *temp = curr->next;
        if (curr->data > reshead->data)
        {
            insertion(reshead, curr);
            //   here res is still max node and at last

            curr = temp;
            //   res->next=curr;
            //   res=curr;
            //   curr=curr->next;
        }
        else
        {
            curr->next = reshead;
            reshead = curr;
            curr = temp;
            //   reshead->next=NULL;
        }
    }
    return reshead;
}

int main(){
   Node*head=buildList();

   head=insertionSort(head);

   while(head){
    cout<<head->data<<" ";
    head=head->next;
   }
   return 0; 
}