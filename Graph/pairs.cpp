#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(1, 10));
    arr.push_back({2, 20});
    for (auto it : arr)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}