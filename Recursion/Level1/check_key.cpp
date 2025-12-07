#include <bits/stdc++.h>
using namespace std;

int find_key(vector<int> arr, int key, int n)
{
    if (n < 0)
        return -1;
    if (arr[n] == key)
        return n;
    int ans = find_key(arr, key, n - 1);
    return ans;
}
int main()
{
    int n, key;
    cin >> n >> key;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << find_key(arr, key, n - 1);
    return 0;
}