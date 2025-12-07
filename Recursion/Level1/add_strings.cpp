#include <bits/stdc++.h>
using namespace std;

void add_string(string &str1, string &str2, int p1, int p2, string &ans, int &carry)
{
    // p1 1236
    //  p2 345  both p1 and p2 < 0

    if (p1 < 0 && p2 < 0)
    {
        if (carry > 0)
            ans.push_back(carry + '0');
        return;
    }
    int num1 = (p1 < 0) ? 0 : (str1[p1] - '0');
    int num2 = (p2 < 0) ? 0 : (str2[p2] - '0');
    int sum = num1 + num2 + carry;
    int last_digit = sum % 10;
    carry = sum /= 10;
    ans.push_back(last_digit + '0');
    return add_string(str1, str2, p1 - 1, p2 - 1, ans, carry);
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    string ans = "";
    int carry = 0;
    add_string(str1, str2, str1.length() - 1, str2.length() - 1, ans, carry);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}