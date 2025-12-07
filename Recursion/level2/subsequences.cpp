#include <bits/stdc++.h>
using namespace std;

void subsequences(string str, string ans, int n)
{
    // abc
    if (n >= str.size())
    {
        cout << ans << " ";
        return;
    }
    subsequences(str, ans + str[n], n + 1);
    subsequences(str, ans, n + 1);

    return;
}
int main()
{
    string str = "";
    cin >> str;
    string ans = "";
    subsequences(str, ans, 0);
    return 0;
}