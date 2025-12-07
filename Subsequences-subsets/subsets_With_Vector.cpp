#include <bits/stdc++.h>
using namespace std;

// vector<string> subsetIterative(string str)
// {
//     // abc
//     // []
//     // [][a]
//     // [][a] [b][ab]
//     vector<string> ans;
//     ans.push_back("");
//     for (int i = 0; i < str.size(); i++)
//     {
//         vector<string> temp;
//         for (int j = 0; j < ans.size(); j++)
//         {
//             temp.push_back(ans[j] + str[i]);
//         }
//         ans.insert(ans.end(), temp.begin(), temp.end());
//     }
//     return ans;
// }
vector<vector<int>> subsetRecursive(vector<int> &arr, vector<int> subset, int i)
{
    vector<vector<int>> ans;
    if (i == arr.size())
    {
        ans.push_back(subset);
        return ans;
    }
    //  [1][2][3]
    //  [] [1]
    // include
    subset.push_back(arr[i]);
    vector<vector<int>> temp = subsetRecursive(arr, subset, i + 1);
    ans.insert(ans.end(), temp.begin(), temp.end());
    // exclude
    subset.pop_back();
    temp = subsetRecursive(arr, subset, i + 1);
    ans.insert(ans.end(), temp.begin(), temp.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    // vector<string> ans = subsetsRecursive(str, "", 0);
    vector<int> subset;
    vector<vector<int>> ans1 = subsetRecursive(str, subset, 0);
    for (auto it : ans1)
    {
        for (auto val : it)
        {
            cout << val;
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}