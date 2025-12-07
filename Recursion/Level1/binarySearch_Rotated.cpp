#include <bits/stdc++.h>
using namespace std;

bool binarySearchRotated(vector<int> &arr, int k, int l, int r)
{
    if (l > r)
        return false;
    // cout << " l " << l << " r " << r << endl;
    int mid = l + (r - l) / 2;
    if (arr[mid] == k)
        return true;
    if (arr[l] <= arr[mid])
    {
        // cout<<" value "<<arr[l]<<" "<<arr[mid]<<" ";
        // cout << " here l " << l << " r " << r << endl;
        if (k >= arr[l] && k < arr[mid])
        {
            return binarySearchRotated(arr, k, l, mid - 1);
        }
        else
            return binarySearchRotated(arr, k, mid + 1, r);
    }
    else
    {
        if (k >= arr[mid] && k <= arr[r])
        {
            return binarySearchRotated(arr, k, mid + 1, r);
        }
        else
            return binarySearchRotated(arr, k, l, mid - 1);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if (binarySearchRotated(arr, 7, 0, n - 1))
        cout << " dekha ";
    else
        cout << " nhi dekha";
    return 0;
}