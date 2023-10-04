#include <bits/stdc++.h>
using namespace std;

int coPrime(int n)
{
    int answer = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            answer = answer - answer / i;
        }
    }
    if (n > 1)
        answer = answer - answer / n;
    return answer;
}
int binExp(int n, int p, int m)
{
    n %= m;
    int result = 1;
    while (p > 0)
    {
        if ((p & 1))
        {
            result = (result * 1LL * n) % m;
        }
        p >>= 1;
        n = (n * 1LL * n) % m;
    }
    return result;
}
int superPow(int a, vector<int> &b)
{
    // int m = coPrime(1337); // coprime of mod =1337 is 1140
    // cout << "coprime = " << m << endl;
    int pow = 1;
    int p = 0;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        p = p + (b[i] * 1LL * pow) % 1140;
        pow = (pow * 10) % 1140;
    }
    cout << p << " " << endl;
    int answer = binExp(a, p, 1337);
    return answer;
}

// here
// int superPow(int a, vector<int> &b)
// {
//     int ans = 0;
//     int power = 1;
//     for (int i = b.size() - 1; i >= 0; i--)
//     {
//         ans = ans + (b[i] * 1LL * power) % 1140;
//         power = (power * 10) % 1140;
//     }
//     cout << ans << endl;
//     int result = binExp1(a, ans, 1337);
//     return result;
// }
int binExp1(int n, int p, int m)
{
    n %= m;
    int result = 1;
    while (p > 0)
    {
        if ((p & 1))
        {
            result = (result * 1LL * n) % m;
        }
        p >>= 1;
        n = (n * 1LL * n) % m;
    }
    return result;
}
int main()
{
    int a;
    vector<int> b = {1, 1, 4, 0}; // 574
    cin >> a;
    cout << superPow(a, b) << endl;
    return 0;
}