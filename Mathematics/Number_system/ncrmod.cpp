#include <bits/stdc++.h>
using namespace std;

int m = 1e6 + 3;
int binExp(long long a, long long p)
{
    a %= m;
    int result = 1;
    while (p > 0)
    {
        if ((p & 1))
            result = (result * 1LL * a) % m;
        p >>= 1;
        a = (a * 1LL * a) % m;
    }
    return result;
}
int wilson_theorem(long long n)
{
    if (n > m)
        return 0;
    int ans = m - 1;
    for (long long i = n + 1; i < m; i++)
    {
        ans = (ans * (binExp(i, m - 2))) % m;
    }
    return ans;
}
int factorial(int n, int range)
{

    int ans = 1;
    for (long long i = n; i > range; i--)
    {
        ans = (ans * 1LL * i) % m;
    }
    // cout << ans << endl;
    return ans;
}
int fact(int n, int r)
{
    int range = max(r, n - r);
    int divident = min(r, n - r);
    // cout << range << endl;
    int ans1 = factorial(n, range);
    // cout << ans1;
    int ann = factorial(divident, 0);
    int ans2 = binExp(ann, m - 2);
    cout << ann << endl;
    cout << ans2 << endl;
    return ((ans1 % m) * ans2) % m;
}
int main()
{
    int n, r;
    cin >> n >> r;
    fact(n, r);
    return 0;
}