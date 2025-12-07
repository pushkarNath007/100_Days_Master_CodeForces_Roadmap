#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int s = 3;
    int i = 0;
    int j = 0;
    vector<vector<int>> ans;
    if(arr.size()%3!=0){
        return ans;
    }
    while (j < arr.size() && i < arr.size() - 2)
    {
        if (i == j)
        {
            j++;
            s--;
        }
        else if (arr[j] - arr[i] <= k)
        {
            s--;
            j++;
        }
        else
        { 
            vector<vector<int>>emp;
           return emp;
        }
        if (s == 0)
        {
            vector<int> temp;
            if (j - i == 3)
            {
                temp.push_back(arr[i]);
                temp.push_back(arr[i + 1]);
                temp.push_back(arr[j - 1]);
                ans.push_back(temp);
            }
            s = 3;
            i = j;
        }
    }
    return ans;
}
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> ans = solve(arr, t);
    if(ans.size()){
    for (auto it : ans)
    {
        // it got whole column
        for (auto val : it)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    }
    return 0;
}