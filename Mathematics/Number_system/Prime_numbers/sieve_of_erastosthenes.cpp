#include <bits/stdc++.h>
using namespace std;

void printing(vector<bool> &arr)
{
    for (int i = 2; i < arr.size(); i++)
    {
        if (arr[i])
            cout << i << " ";
    }
}
void sieveOfErastosthenes(int n)
{
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
    printing(sieve);
}
int main()
{
    int n;
    cin >> n;
    sieveOfErastosthenes(n);
    return 0;
}