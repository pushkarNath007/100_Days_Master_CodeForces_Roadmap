#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> ans;
    vector<int> arr = {1, 2, 3};
    vector<int> arr1 = {4, 4, 5};
    ans.push_back(arr);
    ans.push_back(arr1);
    for (auto it : ans)
    {
        for (auto jj : it)
        {
            cout << jj << " ";
        }
        cout << endl;
    }
    return 0;
}