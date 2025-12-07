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

Node *buildListFromArr(vector<int> &arr)
{
    if (!arr.size())
        return NULL;
    Node *head = new Node(arr[0]);
    Node *iter = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        iter->next = temp;
        iter = iter->next;
    }
    return head;
}
void printing(Node *head)
{
    auto it = head;
    while (it)
    {
        cout << it->data << " ";
        it = it->next;
    }
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
Node* add2Numbers(Node*head1, Node*head2){
   
    head1=reverseLL(head1);
    head2=reverseLL(head2);
    Node*temp1=head1,*temp2=head2;
    int carry = 0;
    Node*ans=new Node(-1);// dummy node for head pointing
    Node*newhead=ans;
    while(temp1 || temp2){
        int var1=0,var2=0;
        if(temp1) var1=temp1->data;
        if(temp2) var2=temp2->data;
        int total=var1+var2+carry;
        Node*temp=new Node(total%10);
        ans->next=temp;
        carry=total/10;
        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next; 
        ans=ans->next;
    }
    while(carry){
        Node*temp=new Node(carry%10);
        ans->next=temp;
        ans=temp;
        carry/=10;
    }
    ans=newhead->next;// newhead points to dummy first node
    // now ans points to head 
    free(newhead);
    ans=reverseLL(ans);
    return ans;
}
int main()
{
    int n,m;
    cin >> n>>m;
    vector<int> arr1(n),arr2(m);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    Node *head1 = buildListFromArr(arr1);
    Node*head2=buildListFromArr(arr2);
    Node*ans=add2Numbers(head1,head2);
    printing(ans);
    return 0;
}