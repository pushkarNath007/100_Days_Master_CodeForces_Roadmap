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
Node *InsertNodeAtPosition(Node *head, int data, int k)
{
    Node *prev = NULL;
    Node *front = head;
    int cnt = 1;
    while (prev || front)
    {
        if (cnt == k)
        {
            if (!prev)
            {
                // for front node position
                Node *temp = new Node(data);
                temp->next = front;
                head = temp;
                return head;
            }
            else if (!prev->next)
            {
                // for last position
                Node*temp= new Node(data);
                prev->next=temp;
                return head;
            }
            else{
                // middle case
                Node *temp = new Node(data);
                prev->next=temp;
                temp->next=front;
                return head;
            }
        }
        prev=front;
        if(front) front=front->next;
        cnt++;
    }
    return head;
}
int main()
{
    int n,k,data;
    cin >> n>>k>>data;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *head = buildListFromArr(arr);
    head = InsertNodeAtPosition(head,data,k);
    printing(head);
    return 0;
}