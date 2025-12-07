#include<bits/stdc++.h>
using namespace std;

vector<int> indexList(vector<int>&arr , int k , int i){
    if(i==arr.size()-1){
        if(arr[i]==k) return {i};
        else return {};
    }
    vector<int> ans;
    if (arr[i] == k) ans.push_back(i);
    vector<int>temp= indexList(arr, k, i + 1);
    ans.insert(ans.end(),temp.begin(),temp.end());
    return ans;
}
int main(){
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];

   vector<int>ans = indexList(arr,4,0);
   for(auto it : ans) cout<<it<<" ";
   return 0; 
}