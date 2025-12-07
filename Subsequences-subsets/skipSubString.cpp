#include <bits/stdc++.h>
using namespace std;

// two ways 
//  ONE WAY 
//  create a new str  add a  char  and check if
// new substr is present in new answer string 
// if its present we know it should be at end
// so   remove  ansstring size -  substr size from last

// 2ND WAY
// REMOVE THE SUBSTR AND AND CALL FOR SMALLER PROBLEM FUNCTION TILL 
// IT DOESNOT GET THE SUBSTR IN STR
//  AND DO IT CALL BY VALUE AND RETURN STR AT END
// BCS YOUR ENDING STR IS CORRECT STRING WITHOUT ANY SUBSTR

void skipASubstr(string &str, string skip, int size)
{
    auto it = str.find(skip);
    if (it == string::npos)
        return;
    if (it != string::npos)
    {
        string substr0 = str.substr(0, it);
        string substr1 = str.substr(it + size, str.size() - 1 - (it + size - 1));
        str = substr0 + substr1;
    }
    skipASubstr(str, skip, size);
}
string skipASubstr2(string str, string skip, int size)
{
    auto it = str.find(skip);
    if (it == string::npos)
        return str;
    if (it != string::npos)
    {
        string substr0 = str.substr(0, it);
        string substr1 = str.substr(it + size, str.size() - 1 - (it + size - 1));
        str = substr0 + substr1;

    }
    return skipASubstr2(str, skip, size);
}
int main()
{
    string str, skip;
    cin >> str >> skip;
    // skipASubstr(str, skip, skip.size());
   
    cout<<skipASubstr2(str,skip , skip.size());
    cout <<endl<< str << endl;
    return 0;
}