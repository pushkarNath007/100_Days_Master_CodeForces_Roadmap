#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1(5, 0);
    vector<int> arr2(10, 0);
    vector<int> arr(15, 0);
    for (int i = 0; i < 15; i++)
    {
        if (i < 5)
            cin >> arr1[i];
        else
            cin >> arr2[i - 5];
    }
    copy(arr1.begin(), arr.end(), arr.begin());
    // copy(arr2.begin(), arr2.end(), arr.begin() + arr2.size());
    for (auto x : arr)
        cout << x << " ";
    return 0;
}