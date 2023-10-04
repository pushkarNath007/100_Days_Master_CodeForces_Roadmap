#include <bits/stdc++.h>
using namespace std;
#define maxi(a, b) max(a, b)
int max_falling_path_sum(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<int> arr(c, 0);
    for (int i = 0; i < c; i++)
    {
        arr[i] = grid[0][i]; // arr= 1 2 10 4
    }

    // for (auto x : arr)
    //     cout << x << endl;

    for (int i = 1; i < r; i++)
    {
        vector<int> temp(c, 0);
        for (int j = 0; j < c; j++)
        {
            int left = -1e8;
            int right = -1e8;
            int top = arr[j];
            if (j > 0)
                left = arr[j - 1];
            if (j < c - 1)
                right = arr[j + 1];
            top = top + grid[i][j];
            left = left + grid[i][j];
            right = right + grid[i][j];
            temp[j] = maxi(top, maxi(left, right));
            cout << i << " , " << j << " = " << temp[j] << " ";
        }
        arr = temp;
        cout << endl;
    }
    int maximum = INT_MIN;
    for (int i = 0; i < c; i++)
    {
        maximum = maxi(maximum, arr[i]);
    }
    return maximum;
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << endl
         << " final result -> " << max_falling_path_sum(grid);
    return 0;
}