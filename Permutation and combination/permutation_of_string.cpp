#include <bits/stdc++.h>
using namespace std;

void permutation(string &str, int i)
{
    // abc
    // abc , acb , bac, bca , cab , cba
    // -->

    // base condition
    if(i==str.size()){
        cout<<str<<" ";
        return;
    }
    vector<string>ans;
    for(int j=i;j<str.size();j++){
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }
    return;
}
int main()
{
    string str;
    cin >> str;
    permutation(str, 0);
    return 0;
}