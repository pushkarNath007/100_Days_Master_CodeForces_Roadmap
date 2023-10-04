#include <bits/stdc++.h>
using namespace std;

vector<int> extendedEuclid(int a, int b)
{
    if (b == 0)
        return {a, 1, 0};
    vector<int> arr = extendedEuclid(b, a % b);
    int y = arr[2];
    arr[2] = arr[1] - (a / b) * arr[2];
    arr[1] = y;
    return arr;
}
vector<int> linearDopamine(int a, int b, int c)
{
    vector<int> arr = extendedEuclid(a, b);
    int k = c / arr[0];

    int x = arr[1] * k;
    int y = arr[2] * k;
    return {x, y};
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ans = linearDopamine(a, b, c);
    for (int x : ans)
        cout << x << " " << endl;
    return 0;
}