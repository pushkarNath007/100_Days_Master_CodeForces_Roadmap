#include <bits/stdc++.h>
using namespace std;

vector<int> extendedEuclideanAlgorithm(int a, int b)
{
    if (b == 0)
        return {a, 1, 0}; // gcd,x,y
    vector<int> arr = extendedEuclideanAlgorithm(b, a % b);
    int y = arr[2];
    arr[2] = arr[1] - (a / b) * arr[2];
    arr[1] = y;
    return arr;
}
int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> arr = extendedEuclideanAlgorithm(a, b);
    for (int x : arr)
        cout << x << " ";
    return 0;
}