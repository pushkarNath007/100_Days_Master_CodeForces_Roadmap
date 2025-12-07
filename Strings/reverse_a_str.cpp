#include <bits/stdc++.h>
using namespace std;

void reverse_string(string &str)
{
    // coding__is__good
    int start = 0;
    vector<string> temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '_')
        {
            start = i;
            while (str[i] != '_' && i < str.length()) i++;
            string val = str.substr(start, i - start);
            temp.push_back(val);
        }
    }
    string ans = temp[temp.size()-1];
    for (int i = temp.size()-2; i >=0; i--)
    {
        ans = ans + "_" + temp[i];
    }
    str = ans;
}
int main()
{
    string str;
    cin >> str;
    reverse_string(str);
    cout << str;
    return 0;
}