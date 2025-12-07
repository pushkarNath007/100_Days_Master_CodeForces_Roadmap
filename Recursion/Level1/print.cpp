#include <bits/stdc++.h>
using namespace std;

void printing_recursion(vector<int> arr, int n)
{
    if (n == 0)
    {
        cout << arr[n] << " ";
        return;
    }
    printing_recursion(arr, n - 1);
    cout << arr[n] << " ";
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printing_recursion(arr, n-1);
    return 0;
}