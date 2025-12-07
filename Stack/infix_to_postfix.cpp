#include <bits/stdc++.h>
using namespace std;
int precedency(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}
bool isChar(char c)
{
    int val = c;
    if (val >= 65 && val <= 90)
        return true;
    else if (val >= 97 && val <= 122)
        return true;
    else if (val >= 48 && val <= 57)
        return true;
    return false;
}
string infixToPostfix(string &s)
{
    string ans = "";

    stack<char> st = stack<char>();

    for (int i = 0; i < s.size(); i++)
    {
        if (isChar(s[i]))
        {
            ans.push_back(s[i]);
            // cout << "ans-> " << ans << endl;
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
            continue;
        }
        else
        {
            if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                if (st.top() == '(')
                    st.pop();
            }
            else
            {
                while (!st.empty()&& precedency(s[i]) <= precedency(st.top()))
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            // cout << s[i] << endl;
        }
    }
    cout<<ans<<endl;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    string ans = infixToPostfix(s);
    cout << ans << endl;
    return 0;
}