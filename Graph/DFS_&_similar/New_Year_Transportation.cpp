#include <bits/stdc++.h>
using namespace std;

void solve(int n, int t, vector<int> &arr)
{
    int pos = 1;
    while (pos <= t)
    {
        // cout << pos << " ";
        if (pos == t)
        {
            cout << "YES";
            return;
        }
        pos = pos + arr[pos - 1];
    }
    cout << "NO";
}
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    solve(n, t, arr);
    return 0;
}