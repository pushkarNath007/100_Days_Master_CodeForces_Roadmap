#include <bits/stdc++.h>
using namespace std;

string removing(string &str)
{
    // base 
   if(str.size()==0) return "";

    // one condition
    char ch=str[0];
    str=str.substr(1,str.size());
    if(ch=='a' || ch=='A'){
       return ""+removing(str); 
    }
    else{
        return ch+removing(str);
    }
}
int main()
{
    string str;
    cin >> str;

    cout << removing(str);
    return 0;
}