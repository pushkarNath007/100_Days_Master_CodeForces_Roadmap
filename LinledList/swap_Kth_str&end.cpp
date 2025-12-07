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
pair<Node*,Node*> traversing(Node*head, int k){
    Node*temp=head;
    Node*prev=NULL;
    int cnt=1;
    while(temp){
        if(cnt==k){
            break;
        }
        cnt++;
        prev=temp;
        temp=temp->next;
    }
    return {prev,temp};
}
Node * swapkthNode(Node*head, int k, int n){
    if(k>n) return head;
    int first=k;
    int last=n-k+1;
    if(first==last) return head;
    // get first val and its prev value
    pair<Node*,Node*>start=traversing(head,first);
    pair<Node*,Node*>end=traversing(head,last);
    //  return {prev,current_node}
    Node*start_prev=start.first, *start_val=start.second;
    Node*end_prev=end.first,  * end_val=end.second;

    if(start_prev){
        // if not null change its next
        start_prev->next=end_val;
    }
    if(end_prev) end_prev->next=start_val;

    // now normal swap with with next
    Node*temp=start_val->next;
    start_val->next=end_val->next;
    end_val->next=temp;

    // update head in only 2 cases
    if(k==1) head=end_val;
    else if(k==n) head=start_val;

    return head;
}
int main()
{
    int n,k;
    cin >> n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *head = buildListFromArr(arr);
    head=swapkthNode(head,k,n);
    printing(head);
    return 0;
}