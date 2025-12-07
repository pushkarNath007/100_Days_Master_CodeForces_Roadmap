#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>arr={1,2,3,4};
   vector<int>temp;
   temp.insert(temp.begin(),arr.begin()+4,arr.end());
   for(auto it:temp) cout<<it<<" ";

   return 0; 
}