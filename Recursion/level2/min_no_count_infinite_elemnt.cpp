#include <bits/stdc++.h>
using namespace std;

int target_sum(vector<int> arr, int k, int count)
{
    if (k == 0)
        return count;
    if (k < 0)
        return INT_MAX;
    int ans = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        // cout << " for i =" << i << " "
        //      << " k = " << k << " ";
        cout<<count<<" ";
        int mini = target_sum(arr, k - arr[i], count + 1);
        cout << mini << " ";
        ans = min(mini, ans);
        cout << ans << endl;
    }
    // cout << " ans =" << ans;
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << target_sum(arr, k, 0);
    return 0;
}