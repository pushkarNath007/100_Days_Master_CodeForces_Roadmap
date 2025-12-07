#include <bits/stdc++.h>
using namespace std;

void subsequences(string &str, int i, string ans)
{
    if (i == str.length())
    {
        cout << ans << " ";
        return;
    }
    subsequences(str, i + 1, ans + str[i]);
    subsequences(str, i + 1, ans);

    return;
}
int main()
{
    string str;
    cin >> str;
    subsequences(str, 0, "");
    return 0;
}