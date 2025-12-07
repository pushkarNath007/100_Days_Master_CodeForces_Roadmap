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
Node* buildLL(){
    int data;
    cin>>data;
    if(data==-1) return NULL;
    Node*head=new Node(data);
    head->next = buildLL();
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

bool isCycle(Node*head1){
    // is present true  
    // if not present false
    Node*fast=head1;
    Node*slow=head1;
    while(fast && fast->next){
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *head = buildLL();
    // printing(head);
    if(isCycle(head)) cout<<"cycle present";
    else cout<<"cycle is not present";
    return 0;
}