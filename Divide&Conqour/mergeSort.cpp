#include <bits/stdc++.h>
using namespace std;

void printing(vector<int> arr, int left, int mid, int right)
{
    cout << "left -> " << left << " mid ->" << mid << " right-> " << right << " val-"
         << " ";
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}
void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> leftarr((mid - left) + 1);
    vector<int> rightarr(right - mid);
    int lr = 0, rl = 0;
    for (int it = left; it <= mid; it++)
    {
        leftarr[lr] = arr[it];
        lr++;
    }
    for (int jt = mid + 1; jt <= right; jt++)
    {
        rightarr[rl] = arr[jt];
        rl++;
    }
    
    int k = left;
    int i = 0, j = 0;

    while (i < leftarr.size() && j < rightarr.size())
    {
        if (leftarr[i] <= rightarr[j])
        {
            arr[k++] = leftarr[i++];
        }
        else
            arr[k++] = rightarr[j++];
    }
    while (i < leftarr.size())
        arr[k++] = leftarr[i++];
    while (j < rightarr.size())
        arr[k++] = rightarr[j++];

    return;
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, arr.size() - 1);

    for (auto it : arr)
        cout << it << " ";
    return 0;
}