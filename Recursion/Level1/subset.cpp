#include <bits/stdc++.h>
using namespace std;

vector<string> subsets(string &str, int i, string sub)
{

    if (i == str.size())
    {
        vector<string> ans;
        ans.push_back(sub);
        // cout << ans[0] << endl;
        return ans;
    }
    vector<string> ans;
    // include
    vector<string> res1 = subsets(str, i + 1, sub + str[i]);
    ans.insert(ans.end(), res1.begin(), res1.end());
    // not included

    res1 = subsets(str, i + 1, sub);
    ans.insert(ans.end(), res1.begin(), res1.end());
    // cout << ans[1] << "-- " << ans[0] << endl;
    return ans;
}
int main()
{
    string str;
    cin >> str;
    vector<string> subset = subsets(str, 0, "");
    for (int i = 0; i < subset.size(); i++)
        cout << subset[i] << " ";
    cout << endl
         << subset.size();
    return 0;
}