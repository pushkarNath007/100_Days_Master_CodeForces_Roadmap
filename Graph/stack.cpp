#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    stack<int> s2;
    s2 = s1;
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}