#include <bits/stdc++.h>
using namespace std;
int mod=1337;
long long binaryExponentIterative(long long n, long long p )
{
    n%=mod;
    long long answer = 1;
    while (p > 0)
    {
        if ((p & 1))
            answer =(answer* n)%mod;
        p /= 2;
        n =(n*n)%mod;
    }
    return answer;
}
int main()
{
    long long n, p;
    cin >> n >> p;
    cout << binaryExponentIterative(n, p) << endl;
    return 0;
}