#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    int length;
    Node(T data, Node *next1)
    {
        this->data = data;
        next = next1;
        length=1;
    }
    Node(T data)
    {
        this->data = data;
        next = NULL;
        length=1;
    }
};
 // head->next->length can be wrong in case next is NULL
int length(Node<int>*head){
    if(!head) return 0;
    return head->length;
}
// recursiverly building while updating height
Node<int>* buildList(vector<int>arr, int i){
    if(i>=arr.size()) return NULL;
    Node<int>*head=new Node<int>(arr[i]);
    head->next=buildList(arr,i+1);
    head->length=length(head->next)+1;
    return head;
}

//  without using recursing and length parameter
//  using traversing count
int Findlength(Node<int>*head){
    int count=0;
    Node<int>*iter=head;
    while(iter){
        count++;
        iter=iter->next;
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node<int>*head=buildList(arr,0);
    cout<<head->length<<endl;
    cout<<Findlength(head)<<endl;
    return 0;
}