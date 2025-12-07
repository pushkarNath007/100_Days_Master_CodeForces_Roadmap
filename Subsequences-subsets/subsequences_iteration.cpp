#include <bits/stdc++.h>
using namespace std;
vector<string> subsequences(string str)
{
    //  abc
    //  []
    //  [] [a]
    //  [] [a] [b] [ab]
    //  [] [a] [b] [ab]  [c] [ac] [bc] [abc]
    vector<string> ans;
    ans.push_back("");
    // cout << ans.size();
    // ans.push_back("ab");
    // ans.push_back(ans[1] + str[1]);
    // string str = "abc";
    for (int i = 0; i < str.length(); i++)
    {
        // i =a
        vector<string> newans;
        for (int j = 0; j < ans.size(); j++)
        {
            newans.push_back(ans[j] + str[i]);
        }
        // cout << str[i] << " ";
        ans.insert(ans.end(), newans.begin(), newans.end());
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    vector<string> ans = subsequences(str);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}