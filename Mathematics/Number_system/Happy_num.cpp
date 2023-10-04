#include <bits/stdc++.h>
using namespace std;

int binExp(int n, int p)
{
    int result = 1;
    while (p > 0)
    {
        if ((p & 1))
            result *= n;
        p >>= 1;
        n *= n;
    }
    return result;
}
int sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += binExp((n % 10), 2);
        n /= 10;
    }
    return sum;
}
bool floydCycle(int n)
{
    int slow = n;
    int fast = n;
    do
    {
        slow = sum(slow);
        fast = sum(sum(fast));
        cout << " slow " << slow << endl
             << " fast " << fast << endl;
        if (slow == 1 || fast == 1)
            return true;
    } while (slow != fast) ;
    return false;
}
int main()
{
    int n;
    cin >> n;
    cout << floydCycle(n);
    return 0;
}