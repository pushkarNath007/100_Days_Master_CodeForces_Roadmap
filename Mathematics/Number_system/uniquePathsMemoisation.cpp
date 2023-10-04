#include <bits/stdc++.h>
using namespace std;
// long long m = 2000000000;
int uniquePathsMemoisation(int m, int n, vector<vector<int>> &arr)
{
    if (arr[m][n] != -1)
        return arr[m][n];
    if (m < 1 || n < 1)
        return 0;
    if (m == 1 && n == 1)
        return 1;
    arr[m][n] = (uniquePathsMemoisation(m, n - 1, arr) + uniquePathsMemoisation(m - 1, n, arr));

    return arr[m][n];
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, -1));

    return uniquePathsMemoisation(m, n, arr);
}
int main()
{
    int m, n;
    cin >> m >> n;

    cout << uniquePaths(m, n);
    return 0;
}