#include <bits/stdc++.h>
using namespace std;

bool binary_search_recursion(vector<int> arr, int left, int right, int key)
{
    if (left > right)
        return false;
    int mid = left + (right - left) / 2;
    if (arr[left] == key || arr[right] == key || arr[mid] == key)
        return true;
    if (key < arr[mid])
        return binary_search_recursion(arr, left, mid - 1, key);
    else
        return binary_search_recursion(arr, mid + 1, right, key);
}
int main()
{
    int n, key;
    cin >> n >> key;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (binary_search_recursion(arr, 0, n - 1, key))
        cout << "present";
    else
        cout << "absent";
    return 0;
}