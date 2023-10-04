#include <bits/stdc++.h>
using namespace std;
// prime no

int binExp(int a, int p, int m)
{
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
int fermatTheorem(int a, int m)
{
    // a^M-2 %m ==a^-1
    // (a/b)%m
    int mmi = binExp(a, m - 2, m) % m;
    return mmi;
}
int main()
{
    int a, m;
    cin >> a >> m;
    cout << fermatTheorem(a, m);
    return 0;
}