#include <bits/stdc++.h>
using namespace std;

int sum_of_factors(int n)
{
    int sum = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;
            // cout << "->" << i << " ";
            if (n / i != i)
            {
                sum += n / i;
                // cout << "->" << n / i << endl;
            }
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int ans = sum_of_factors(n);
    cout << endl
         << "sum of all distinct factors ==  " << ans;

    return 0;
}