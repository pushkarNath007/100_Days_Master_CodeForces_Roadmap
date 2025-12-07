#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*back;
    Node(int data){
        this->data=data;
        next=NULL;
        back=NULL;
    }
};
 
Node* buildDDL(vector<int>&arr){
    if(!arr.size()) return NULL;
    Node*head=new Node(arr[0]);
    Node*prev=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=prev->next;
    }
    return head;
}

Node* insertion(Node*head, int data, int k){
    Node*front=head;
    int cnt=1;
    while(front){
       
        if(!front->next && k-cnt==1){
            cout<<front->data<<" "<<cnt<< endl;
            Node*temp=new Node(data);
            front->next=temp;
            temp->back=front;
            break;
        }
        else if(cnt==k){
            if(!front->back){
                // head case 
                Node*temp=new Node(data);
                temp->next=head;
                head->back=temp;
                head=temp;
                break;
            }
            else{
                // mid case
                Node*temp= new Node(data);
                Node*prev=front->back;
                prev->next=temp;
                temp->back=prev;
                temp->next=front;
                front->back=temp;
                break;
            }
        }
        cnt++;
        front=front->next; 
    }
    return head;
}
void traversing(Node*head){
    Node*iter=head;
    while(iter){
        cout<<iter->data<<" ";
        iter=iter->next;
    }
}
int main(){
   int n, data,k;
   cin>>n>>data>>k;
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   Node*head=buildDDL(arr);
   head=insertion(head,data,k);
   traversing(head);
   return 0;
}