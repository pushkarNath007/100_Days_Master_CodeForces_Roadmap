#include <bits/stdc++.h>
using namespace std;

void subsequences(string &str, int i, string ans)
{
    if (i == str.length())
    {
        cout << ans << " ";
        return;
    }
    // excluding
    subsequences(str, i + 1, ans);
    // include
    subsequences(str, i + 1, ans+str[i]);
    // ascii value
    int asses = (str[i]);
    subsequences(str, i + 1, ans+to_string(asses));
    return;
}
int main()
{
    string str;
    cin >> str;
    subsequences(str, 0, "");
    return 0;
}