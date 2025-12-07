#include <bits/stdc++.h>
using namespace std;

string removing(string &str)
{
    if (str.size() == 0)
        return str;

    int idx = str.find('a');
    if (idx != string::npos)
    {
        // cout << idx << endl;
        string first = str.substr(0, idx);
        // cout << first << endl;
        string last = str.substr(idx + 1, str.size() - idx);
        // cout << last << endl;
        str = first + last;
        return removing(str);
    }

    return str;
}
int main()
{
    string str;
    cin >> str;

    cout << removing(str);
    return 0;
}