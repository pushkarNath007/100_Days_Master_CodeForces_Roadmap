#include <bits/stdc++.h>
using namespace std;
void func(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        stringstream ss(arr[i]);
        int side1, side2, side3;
        ss >> side1 >> side2 >> side3;
        cout << side1 + side2 + side3 << endl;
    }
}
int main()
{
    vector<string> arr = {"1 2 2 ", "2 2 2", "1 2 3"};
    func(arr);
    return 0;
}