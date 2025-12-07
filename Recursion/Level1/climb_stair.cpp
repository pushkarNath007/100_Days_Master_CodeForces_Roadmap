#include <bits/stdc++.h>
using namespace std;

int printing(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int climbStairs(int n)
{
    vector<int> arr(n + 1, 0);
    arr[0] = arr[1] = 1;
    // printing(arr);
    if (n <= 3 && n >= 0)
        return n;
    for (int i = 2; i <= n; i++)
    {
        int l = ((i - 1) < 0) ? 0 : arr[i - 1];
        int r = ((i - 2) < 0) ? 0 : arr[i - 2];
        // cout << i - 1 << " -> " << arr[i - 1] << " " << i - 2 << "->" << arr[i - 2] << endl;
        // arr[i] = (arr[i - 1] + arr[i - 2]);
        arr[i] = l + r;
    }
    // printing(arr);
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n);
    return 0;
}