#include <bits/stdc++.h>
using namespace std;

map<char, string> mpp{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}};

vector<string> PhoneCombination(string &str, string ans, int i)
{
    // str= 23
    vector<string> final;
    if (i == str.size())
    {
        final.push_back(ans);
        return final;
    }
    for (auto it : mpp[str[i]])
    {
        ans.push_back(it);
        vector<string> temp = PhoneCombination(str, ans, i + 1);
        ans.pop_back();
        final.insert(final.end(), temp.begin(), temp.end());
    }
}
int main()
{
    string str;
    cin >> str;
    vector<string> ans = PhoneCombination(str, "", 0);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}