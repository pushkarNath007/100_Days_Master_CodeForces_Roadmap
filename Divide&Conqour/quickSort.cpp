#include <bits/stdc++.h>
using namespace std;

int dividing(vector<int> &arr, int left, int right)
{
    // 4 1 7 8 5 12 2 3 6 10
    // 4 1 3 2 5 12 8 7 6 10
    int pivot = left;
    while (left < right)
    {
        while (arr[left] <= arr[pivot])
            left++;
        while (arr[right] > arr[pivot])
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[pivot], arr[right]); // right last point will be the last <=arr[pivot] value
    return right;
}
void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int pivot = dividing(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, arr.size() - 1);

    for (auto it : arr)
        cout << it << " ";
    return 0;
}