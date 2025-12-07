#include <bits/stdc++.h>
using namespace std;

bool wildcard(string &s, string &part, int i, int j)
{
    // base condition
    if (i >= s.length() && j >= part.length())
    {
        return true;
    }

    if (s[i] == part[j] || part[j] == '?')
    {
        bool ans = wildcard(s, part, i + 1, j + 1);
        return ans;
    }
    else if (part[j] == '*')
    {
        bool ans1 = wildcard(s, part, i, j + 1);
        bool ans2 = wildcard(s, part, i + 1, j);
        if (ans1 || ans2)
            return true;
        else
            return false;
    }
    return false;
}
int main()
{
    string s, part;
    cin >> s >> part;
    cout << wildcard(s, part, 0, 0);
    return 0;
}