#include<bits/stdc++.h>
using namespace std;

long long binaryExponent(int n,int p){
   if(p==0) return 1;
   int product=binaryExponent(n,p/2);
   product*=product;
   if((n&1)) product*=n;
   return product;
}
int main(){
   int n,p;
   cin>>n>>p;
   cout<< binaryExponent(n,p);
   return 0; 
}