#include<bits/stdc++.h>
using namespace std;

vector<string> uniqueSubsequences(string str, string & output, int n){
    // a b b
    vector<string> ans;
    if(n==str.size()){
        ans.push_back(output);
        return ans;
    }
    sort(str.begin(),str.end());
    ans.push_back(output);
    for(int i=n;i<str.length();i++){
        if(i>n && str[i]==str[i-1]) continue;
        output.push_back(str[i]);
        vector<string>temp=uniqueSubsequences(str,output,i+1);
        output.pop_back();
        ans.insert(ans.end(),temp.begin(),temp.end());
    }
    return ans;
    
}
int main(){
   string str;
   cin>>str;
   string output="";
   vector<string>ans=uniqueSubsequences(str,output,0);
    for(auto it:ans) cout<<it<<" ";

   return 0; 
}