#include <bits/stdc++.h>
using namespace std;

vector<bool> sieveOfEratosthene(int n)
{
    // cout << n << endl;
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
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
    // for (auto x : sieve)
    //     cout << x << " ";
    return sieve;
}
vector<bool> segmentedSieve(int l, int r)
{
    vector<bool> sieve = sieveOfEratosthene(sqrt(r));
    vector<int> primes;
    for (int i = 2; i <= sqrt(r); i++)
    {
        // cout << i << " ";
        if (sieve[i])
            primes.push_back(i);
    }
    for (auto x : primes)
        cout << x << " ";

    vector<bool> segmented(r - l + 1, true);
    for (int i = 0; i < primes.size(); i++)
    {
        int first = (l / primes[i]) * primes[i];
        if (first < l)
            first + primes[i];
        first = max(first, primes[i] * primes[i]);
        for (int j = first; j <= r; j += primes[i])
        {
            segmented[j - l] = false;
        }
    }
    return segmented;
}
int main()
{
    int l, r;
    cin >> l >> r;
    vector<bool> segmented = segmentedSieve(l, r);

    // for (auto x : segmented)
    //     cout << x << " ";
    for (int i = l; i <= r; i++)
    {
        if (segmented[i - l])
            cout << i << " ";
    }
    return 0;
}