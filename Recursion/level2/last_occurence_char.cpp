#include<bits/stdc++.h>
using namespace std;

int last_occurence(string str, int i , char key){
    //  a b c d d e d f     target =d
    if(i<0) return -1;
    if(str[i]==key) return i;
    int last=last_occurence(str,i-1, key);
    return last;
}
int main(){
   string str;
   char key;
   cin>>str>>key;
   cout<<last_occurence(str,str.length()-1,key);
   return 0; 
}