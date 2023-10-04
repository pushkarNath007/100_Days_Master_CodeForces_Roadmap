#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> mpp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    int sum = 0;
    sum = mpp[s[s.length() - 1]];
    cout << "last value" << sum << endl;
    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (mpp[s[i]] < mpp[s[i + 1]])
            sum -= mpp[s[i]];
        else
            sum += mpp[s[i]];
    }
    cout << sum;
    return 0;
}