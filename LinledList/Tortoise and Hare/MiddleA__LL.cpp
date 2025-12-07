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
Node * middle(Node*head){
    Node*fast=head, *slow=head;
    while(fast && fast->next){
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
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
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *head = buildListFromArr(arr);
    // printing(head);
    Node*mid=middle(head);
    cout<<mid->data<<" ";
    return 0;
}