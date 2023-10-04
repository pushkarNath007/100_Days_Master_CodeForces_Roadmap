#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    int n = grid[0].size(); // col size
    int m = grid.size();    // row size
    vector<int> arr(n, 1);

    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == 1)
            arr[i] = 0;
    }

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    for (int i = 1; i < m; i++)
    {
        vector<int> temp(n, 0);
        (grid[i][0]) ? temp[0] = 0 : temp[0] = 1;
        // cout << " temp of row " << i << " - >" << temp[0] << " ";
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == 1)
                temp[j] = 0;
            else
                temp[j] = temp[j - 1] + arr[j];
        }
        arr = temp;
    }
    return arr[n - 1];
}
int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    grid[0][1] = 1;

    cout << uniquePathsWithObstacles(grid);
    return 0;
}