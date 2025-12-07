#include<bits/stdc++.h>
using namespace std;


int max_sum(vector<int>arr, int ans, int i){
    //   2 1 4 9
    if(i>=arr.size()) return ans;
    // including ith element
   int ans1= max_sum(arr, ans+arr[i],i+2);
   // excluding ith element
   int ans2= max_sum(arr,ans,i+1);

   return max(ans1,ans2);
}
int main(){
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
    cout<<max_sum(arr,0,0);
   return 0; 
}