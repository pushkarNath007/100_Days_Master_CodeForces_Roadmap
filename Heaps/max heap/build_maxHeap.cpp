#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int *arr=new int[10000];
    int size;
    Heap(){
        size=0;
    }
    void insertNode(int data){
        size+=1;
        arr[size]=data;
        int i=size;
        while(i>1 && arr[i]>arr[i/2]){
            swap(arr[1],arr[i/2]);
            i=i/2;
        }
    } 
    bool deleteNode(){
        if(!size) return false;
        arr[1]=arr[size];
        size--;
        int maxid=1;
        int i=1;
        while(i<size){
            int child=i*2;
            if(child <=size){
                if(arr[child]>arr[maxid]) maxid=child;
            }
            if(child+1 <=size){
                if(arr[child+1]>arr[maxid]) maxid=child+1;
            }
            if(i==maxid) break;
            swap(arr[i],arr[maxid]);
            i=maxid;
        }
        return true;
    }  
};
int main(){
   
   return 0; 
}