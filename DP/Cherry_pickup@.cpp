#include <bits/stdc++.h>
using namespace std;
int func(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 > c - 1 || j2 < 0 || j2 > c - 1)
        return -1e8;
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    int maxi = INT_MIN;
    for (int dji = -1; dji <= 1; dji++)
    {
        for (int djj = -1; djj <= 1; djj++)
        {
            int ans = func(i + 1, j1 + dji, j2 + djj, r, c, grid, dp);
            if (j1 == j2)
                ans = grid[i][j1] + ans;
            else
                ans = grid[i][j1] + grid[i][j2] + ans;
            maxi = max(maxi, ans);
        }
    }
    dp[i][j1][j2] = maxi;
    return maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return func(0, 0, c - 1, r, c, grid, dp);
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
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //         cout << grid[i][j];
    // }
    cout << cherryPickup(grid);
    return 0;
}