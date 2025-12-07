#include <bits/stdc++.h>
using namespace std;

bool check_sorted(vector<int> arr, int n)
{
    if (n == 0)
        return true;
    if (arr[n] < arr[n - 1])
        return false;
    return check_sorted(arr, n - 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (check_sorted(arr, n - 1))
        cout << " sorted";
    else
        cout << "not sorted";
    return 0;
}