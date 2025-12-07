#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int temp = n;
    int sum = 0;
    int i = 1;
    int var=0;
    while (n)
    {
        sum += (temp % 10);
        //  var = (var * 10)+ (temp % 10);
        temp /= 10;
    }
    cout << sum;
    if (var == n)
        cout << endl
             << "palindrome";
    return 0;
}