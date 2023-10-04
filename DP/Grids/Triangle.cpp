#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{

    int r = triangle.size();

    int c = triangle[0].size();
    // here in such question every column has different size so
    // so in leetcode   int c =traingle[r-1].size();

    // cout << r << "";
    vector<vector<int>> arr(r, vector<int>(c, 0));

    for (int i = 0; i < c; i++)
        arr[r - 1][i] = triangle[r - 1][i];

    // for (int i = 0; i < c; i++)
    //     cout << arr[r - 1][i];

    //        9 10
    //  2 ->  7 6 10

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int st = arr[i + 1][j] + triangle[i][j];
            int diag = arr[i + 1][j + 1] + triangle[i][j];
            arr[i][j] = min(st, diag);
            // cout << i << " -> " << st << " " << diag << " " << arr[i][j] << endl;
        }
    }
    return arr[0][0];
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> triangle(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> triangle[i][j];
        }
    }
    cout << minimumTotal(triangle);

    return 0;
}