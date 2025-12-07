#include<bits/stdc++.h>
using namespace std;
void heapify(int *arr,int size,int i){
    if(i>=size) return;
    // cout<<endl<<" before swap i = "<<i<<" value "<<arr[i]<<" ";
    int maxid=i;
    int child=i*2;
    if(child<=size) {
        // cout<<" before swap child = "<< arr[child]<<" ";
        if(arr[child]>arr[maxid]) maxid=child;
    }
    if(child+1 <=size){
        // cout << " before swap child+1 = " << arr[child+1] << " ";
        if (arr[child+1] > arr[maxid])
            maxid = child+1;
    }
    if(i==maxid) return;
    swap(arr[maxid],arr[i]);
    i=maxid;
    heapify(arr,size,i);
    return;
}
void buildHeap(int *arr, int n ){
    for(int index=n/2;index>=1;index--){
        heapify(arr,n,index);
    }
}
void heapSort(int *arr, int size){
    buildHeap(arr,size);
    int n=size;
    while(n>1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}
void deleteNode(int * arr, int &size)
{
    if (!size)
        return ;
    arr[1] = arr[size];
    size--;
    int maxid = 1;
    int i = 1;
    while (i < size)
    {
        int child = i * 2;
        if (child <= size)
        {
            if (arr[child] > arr[maxid])
                maxid = child;
        }
        if (child + 1 <= size)
        {
            if (arr[child + 1] > arr[maxid])
                maxid = child + 1;
        }
        if (i == maxid)
            break;
        swap(arr[i], arr[maxid]);
        i = maxid;
    }
    return ;
}
int main(){
   int arr[9]={-1,8,7,6,5,4,3,2,1};
   int size = 8;
   heapSort(arr,size);
   for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
//    buildHeap(arr,size);
   
  
//    deleteNode(arr,size);
//    cout << arr[1]<<" ";
//    deleteNode(arr,size);
//    cout << arr[1]<<" ";
//    deleteNode(arr,size);
//    cout << arr[1]<<" ";
//    deleteNode(arr,size);
//    cout << arr[1]<<" ";
//    deleteNode(arr,size);
//    cout << arr[1]<<" ";
//    deleteNode(arr,size);
//    cout << arr[1]<<" ";
//    deleteNode(arr, size);
//    cout << arr[1] << " ";
   return 0; 
}