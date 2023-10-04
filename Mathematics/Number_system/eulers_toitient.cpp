#include <bits/stdc++.h>
using namespace std;

long eulerToitient(long n)
{
    long ans = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            ans = ans - ans / i;
        }
    }
    if (n > 1)
    {
        ans = ans - ans/n;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    cout << eulerToitient(n);
    return 0;
}