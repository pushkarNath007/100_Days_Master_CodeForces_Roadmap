#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        back = NULL;
    }
};

Node *buildDDL(vector<int> &arr)
{
    if (!arr.size())
        return NULL;
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = prev->next;
    }
    return head;
}

Node *reverseDDL(Node *head)
{
    Node *front = head;
    while (front)
    {
        Node *temp = front->next;
        front->next = front->back;
        front->back = temp;
        if (!temp)
            head = front;
        front = temp; // or front = front->back;
    }
    return head;
}
void traversing(Node *head)
{
    Node *iter = head;
    while (iter)
    {
        cout << iter->data << " ";
        iter = iter->next;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *head = buildDDL(arr);
    head = reverseDDL(head);
    traversing(head);
    return 0;
}