#include <bits/stdc++.h>
using namespace std;

int largest_prime(int n)
{
    int ans = n;
    if (n % 2 == 0)
    {
        ans = 2;
        while (n % 2 == 0)
        {
            n /= 2;
        }
    }
    if (n % 3 == 0)
    {
        ans = 3;
        while (n % 3 == 0)
            n /= 3;
    }
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0)
        {
            ans = i;
            while (n % i == 0)
                n /= i;
        }
        if (n % (i + 2) == 0)
        {
            ans = i + 2;
            while (n % (i + 2) == 0)
                n /= (i + 2);
        }
    }
    if (n > 1)
        ans = n;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << largest_prime(n) << endl;
    return 0;
}