#include <bits/stdc++.h>
using namespace std;
// long long m = 2000000000;
int uniquePaths(int m, int n)
{
    if (m < 1 || n < 1)
        return 0;
    if (m == 1 && n == 1)
        return 1;
    int sum = 0;
    sum = (uniquePaths(m, n - 1) + uniquePaths(m - 1, n)) % m;
    return sum;
}
int main()
{
    int m, n;
    cin >> m >> n;

    cout << uniquePaths(m, n);
    return 0;
}