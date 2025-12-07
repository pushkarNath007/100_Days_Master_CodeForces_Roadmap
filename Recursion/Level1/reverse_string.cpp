#include<bits/stdc++.h>
using namespace std;

void reverse(string &str, int left , int right){
    if(left>=right) return;
    swap(str[left],str[right]);
    return reverse(str,left+1,right-1);
}
int main(){
   string str;
   cin>>str;
    reverse(str,0,str.length()-1);
    cout<<str<<endl;
   return 0; 
}