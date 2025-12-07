#include <bits/stdc++.h>
using namespace std;

int maxi(vector<int> arr, int n)
{
    if (n == 0)
        return arr[n];
    int ans = max(arr[n], maxi(arr, n - 1));
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxi(arr, n);
    return 0;
}