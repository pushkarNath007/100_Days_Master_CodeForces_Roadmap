#include <bits/stdc++.h>
using namespace std;
int target_sum(vector<int> arr, int k, int i, int count)
{
    if (arr[i] == k)
    {
        return ++count;
    }
    if (i < 0)
        return INT_MAX;
    int cnt = min((arr[i] > k) ? INT_MAX : target_sum(arr, k - arr[i], i - 1, ++count), target_sum(arr, k, i - 1, count));
    // cout << cnt << " " << i << endl;
    return cnt;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int count = 0;
    count = target_sum(arr, k, n - 1, count);
    if (count == INT_MAX)
        cout << " not found";
    else
        cout << count;
    return 0;
}