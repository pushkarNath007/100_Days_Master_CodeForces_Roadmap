#include <bits/stdc++.h>
using namespace std;

vector<int> unique_prime(int n)
{
    vector<int> ans;
    if (n % 2 == 0)
    {
        ans.push_back(2);
        while (n % 2 == 0)
        {
            n /= 2;
        }
    }
    if (n % 3 == 0)
    {
        ans.push_back(3);
        while (n % 3 == 0)
            n /= 3;
    }
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
                n /= i;
        }
        if (n % (i + 2) == 0)
        {
            ans.push_back(i + 2);
            while (n % (i + 2) == 0)
                n /= (i + 2);
        }
    }
    if (n > 1)
        ans.push_back(n);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = unique_prime(n);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}