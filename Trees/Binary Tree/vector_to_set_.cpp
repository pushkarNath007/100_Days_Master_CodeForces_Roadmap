#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 5, 4, 3};
    set<int> s1;
    s1.insert(arr.begin(), arr.end());
    for (auto it : s1)
        cout << it << " ";
    return 0;
}