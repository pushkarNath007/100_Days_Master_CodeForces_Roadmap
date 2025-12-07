#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, bool> mpp;
    mpp[2] = true;
    mpp[2] = false;
    // mpp[2] = true;
    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}