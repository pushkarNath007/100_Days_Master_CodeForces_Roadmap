#include <bits/stdc++.h>
using namespace std;
#define MAX 5000
int p = 1e9 + 7;
vector<vector<int>> arr(MAX + 1, vector<int>(MAX + 1));
void nCrMatrix()
{
    for (int i = 1; i <= MAX; i++)
        arr[i][0] = 1;
    arr[1][1] = 1;
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 1; j <= MAX; j++)
        {
            if (i == 1 && j == 1)
                continue;
            arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % p;
        }
    }
}
int binExp(int n, int b)
{
    int result = 1;
    n %= p;
    while (b > 0)
    {
        if ((b & 1))
            result = (result * n) % p;
        b >>= 1;
        n = (n * n) % p;
    }
    return result;
}
void printing(int n, vector<int> arr)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int matrixValue(int n, int r)
{
    return arr[n][r];
}
int productOfMiddleElementSubsequenes(vector<int> &arr, int n, int k)
{
    vector<int> ans(n);
    int total = matrixValue(n - 1, k - 1);
    // cout << total << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        ans[i] = total - matrixValue(n - 1 - i, k - 1) - matrixValue(i, k - 1);
        // cout << ans[i] << " value of i =>"
        //      << " " << i << " ";
    }
    // printing(n, ans);
    int result = 1;
    for (int i = 0; i < ans.size(); i++)
    {
        int res = binExp(arr[i], (ans[i] % (p - 1))) % p;
        // cout << res << " "
        //      << "for " << arr[i] << " power " << ans[i] << endl;
        result = (res * result) % p;
    }
    return result;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    nCrMatrix();
    cout << productOfMiddleElementSubsequenes(arr, n, k);
    return 0;
}