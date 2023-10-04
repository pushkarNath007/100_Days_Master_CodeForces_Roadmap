#include <bits/stdc++.h>
using namespace std;

int trailing_zero_at_end(int n)
{
    if (n < 5)
        return 0;
    int count = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        count += n / i;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    cout << trailing_zero_at_end(n) << endl;
    return 0;
}