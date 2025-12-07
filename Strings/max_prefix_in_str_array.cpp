#include <bits/stdc++.h>
using namespace std;

void printing(vector<string> &arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

string prefix(vector<string> &arr)
{
    // find the min string array
    string mini = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i].length() < mini.length())
        {
            mini = arr[i];
        }
    }
    // cout << mini;
    int i = 0;
    while (mini.size() && i < arr.size())
    {
        if (arr[i].find(mini) == string::npos)
        {
            mini = mini.substr(0, mini.length() - 1);
        }
        else
            i++;
    }
    if (mini.size())
        return mini;

    return "-1";
}
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // printing(arr);
    cout << prefix(arr);
    return 0;
}