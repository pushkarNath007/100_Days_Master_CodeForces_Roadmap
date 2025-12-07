#include <bits/stdc++.h>
using namespace std;

long long money(vector<long long> arr)
{
    if (arr[0] >= 1 && arr[0] <= 100)
        return 3500 + (15 * arr[0]);
    else if (arr[0] >= 11 && arr[0] < +100)
        return 14 * arr[0];
    else if (arr[0] <= 101 && arr[0] >= 1000)
        return 12 * arr[0];
    else
        return 11 * arr[0];
}
int main()
{
    vector<long long> arr(1, 0);
    vector<string> name();
    vector<string> license;
    // cout << "enter the km";
    cin >> arr[0];
    long long ans = money(arr);
    // cout << ans;
    double gst = (float)((18 * ans) / 100);
    double res = (double)(ans + (gst + (double)((5 * ans) / 100)));
    cout << gst;
    return 0;
}