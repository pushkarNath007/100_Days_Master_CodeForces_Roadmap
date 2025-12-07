#include<bits/stdc++.h>
using namespace std;
// cal sum of smallest element in every sub array

int smallestElement(vector<int>&arr){
//   3 1 5
    stack<int>s1;
    vector<int>left,right;
    // calculate no of greater element from left
    for(int i=0;i<arr.size();i++){

        while(!s1.empty() || s1.top()<arr[i]) s1.pop();
        if(s1.empty()){
            left.push_back(1);
            s1.push(arr[i]);
        }
        else{
            left.push_back(s1.size()+1);
            s1.push(arr[i]);
        }
    }
    while(!s1.empty()) s1.pop();

    // calculating no of greater element at right
}
int main(){
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];

   return 0; 
}