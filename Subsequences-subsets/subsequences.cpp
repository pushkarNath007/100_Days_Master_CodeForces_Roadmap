#include <bits/stdc++.h>
using namespace std;

vector<string> subsetsRecursive(string str, string subset, int i)
{
    //  abc
    //  [] [a]
    //  [ab]
    vector<string> ans;
    if (i == str.size())
    {
        ans.push_back(subset);
        return ans;
    }
    // include
    vector<string> temp = subsetsRecursive(str, subset + str[i], i + 1);
    ans.insert(ans.end(), temp.begin(), temp.end());
    // exclude
    temp = subsetsRecursive(str, subset, i + 1);
    ans.insert(ans.end(), temp.begin(), temp.end());
    return ans;
}
vector<string> subsetIterative(string str)
{
    // abc
    // []
    // [][a]
    // [][a] [b][ab]
    // [1] [ 2] [ 1 2]
    vector<string> ans;
    ans.push_back("");
    for (int i = 0; i < str.size(); i++)
    {
        vector<string> temp;
        for (int j = 0; j < ans.size(); j++)
        {
            temp.push_back(ans[j] + str[i]);
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    // vector<string> ans = subsetsRecursive(str, "", 0);
    vector<string> ans1 = subsetIterative(str);
    // for (auto it : ans)
    //     cout << it << " ";
    cout << endl;
    for (auto it : ans1)
        cout << it << " ";
    return 0;
}