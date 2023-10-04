#include <bits/stdc++.h>
using namespace std;
int m = 709;
int nCrMatrix(int n, int r)
{
    vector<vector<int>> arr(n + 1, vector<int>(r + 1));
    for (int i = 1; i <= n; i++)
        arr[i][0] = 1;
    arr[1][1] = 1;
    for (int i = 1; i <= n; i++)
    { // for row = n of nCr
        for (int j = 1; j <= r; j++)
        { // for col = r of nCr so atleat 2C1
            if (i == 1 && j == 1)
                continue;
            arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % m;
        }
    }
    return arr[n][r];
}
int main()
{
    int n, r;
    cin >> n >> r;
    cout << nCrMatrix(n, r);
    return 0;
}