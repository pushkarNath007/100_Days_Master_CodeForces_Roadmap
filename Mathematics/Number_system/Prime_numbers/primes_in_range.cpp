#include <bits/stdc++.h>
using namespace std;

int countPrimes(int l, int r)
{
    int n = sqrt(r);
    // cout << n;
    vector<bool> sieve(n + 1, true);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
            primes.push_back(i);
    }

    // printing primes for checking
    // for (auto x : primes)
    //     cout << x << endl;

    vector<bool> segment(r - l + 1, true);

    for (int i = 0; i < primes.size(); i++)
    {
        int first = (l / primes[i]) * primes[i];
        if (first < l)
            first += primes[i];
        first = max(first, primes[i] * primes[i]);
        // cout << "first" << first << " ";
        for (int j = first; j <= r; j += primes[i])
        {
            segment[j - l] = false;
        }
    }
    if (l == 1)
        segment[l - l] = false;
    int count = 0;

    // // printing only for cheking 1 to 10
    // for (int i = 0; i <= r - l; i++)
    // {
    //     if (segment[i])
    //         cout << i << " = " << i + l << endl;
    // }
    // // finished here
    for (int i = 0; i < segment.size(); i++)
    {
        if (segment[i])
            count++;
    }
    return count;
}
int main()
{
    int l, r;
    cin >> l >> r;
    int count = countPrimes(l, r);
    return 0;
}