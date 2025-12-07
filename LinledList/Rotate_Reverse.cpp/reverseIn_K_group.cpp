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
int sizeOfLL(Node * head){
    Node*iter=head;
    int cnt=0;
    while(iter){
        iter=iter->next;
        cnt++;
    }
    // iter moves to NULL but cnt ++ so we make cnt =0 at head
    return cnt;
}
Node *reverseALL(Node *head)
{
    Node *prev = NULL;
    Node *iter = head;
    while (iter)
    {
        Node *temp = iter->next;
        iter->next = prev;
        prev = iter;
        iter = temp;
    }
    return prev;
}
Node *reverseInKGroup(Node *head, int k)
{
    if (!head)
        return head;
    int size=sizeOfLL(head);
     k=k%size;
    if(k==0) return head;
    Node *prev = NULL;
    Node *nexthead = NULL;
    Node *end = head;
    Node *start = head;
    int cnt = 1;
    while (end && cnt < k)
    { 
        end = end->next;
        cnt++;
    }
    if (!end)
    {
        return head;
    }
    nexthead = end->next;
    end->next = NULL;
    head = reverseALL(start);
    // first group is reversed here
    prev = start; // start pointing to prev head now end of group 1
    end = nexthead;
    start = nexthead;
    // printing(head);
    while (start)
    {
        int cnt = 1;
        while (end && cnt < k)
        {
            end = end->next;
            cnt++;
        }
        if (!end)
        {
            // means last group unchanged just point its head
            // to last group lastvalue->next;
            prev->next = start;
            break;
        }
        nexthead = end->next;
        end->next = NULL;
        end = reverseALL(start);
        prev->next = end; // linked both group here
        prev = start;     // start point to end point after reverse
        start = nexthead;
        end = nexthead;
    }
    return head;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *head = buildListFromArr(arr);
    head = reverseInKGroup(head, k);
    printing(head);
    return 0;
}