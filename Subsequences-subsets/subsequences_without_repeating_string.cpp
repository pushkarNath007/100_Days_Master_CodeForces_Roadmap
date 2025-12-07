#include <bits/stdc++.h>
using namespace std;
vector<string> subsequences(string &str)
{
    sort(str.begin(),str.end());
    //  abb
    //  []
    //  [] [a]  s   e
    //  [] [a] [b] [ab]   s
    //  [] [a] [b] [ab]  [b] [ab] [bb] [abb]
    vector<string> ans;
    ans.push_back("");
    // cout << ans.size();
    // ans.push_back("ab");
    // ans.push_back(ans[1] + str[1]);
    // string str = "abc";
    int start = 0;
    int end = 0;
    for (int i = 0; i < str.length(); i++)
    {
        // i =a
        vector<string> newans;
        for (int j = 0; j < ans.size(); j++)
        {
            string temp = (ans[j] + str[i]);
            if (ans[start] == temp)
                start++;
            else
                newans.push_back(temp);
        }
        // cout << str[i] << " ";
        ans.insert(ans.end(), newans.begin(), newans.end());
        start = end + 1;
        end = ans.size() - 1;
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