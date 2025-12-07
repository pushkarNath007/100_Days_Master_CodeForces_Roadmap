#include <bits/stdc++.h>
using namespace std;

bool goldRush(int n, int m){
    if(n==m) return true;
    if(n<m) return false;
    if(n%3==0 ){
       bool ans1 = goldRush(n/3,m);
       bool ans2 = goldRush(2*(n/3),m);
       if(ans1 || ans2) return true;
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    if(goldRush(n,m)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return ;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}