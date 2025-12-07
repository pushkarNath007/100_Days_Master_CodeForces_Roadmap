#include <bits/stdc++.h>
using namespace std;

void printing(vector<vector<int>> &maze)
{
    cout << endl;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[0].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int no_of_ways(vector<vector<int>> &maze, int i, int j, vector<vector<bool>> &check)
{
    // cout << endl
    //      << i << " " << j << " ";
    // outer boundary condition
    if (i < 0 || j < 0 || i >= maze.size() || j >= maze[0].size())
    {
        return 0;
    }
    // maze going condition if 1 can go otherwise cant go
    if (!maze[i][j])
    {
        return 0;
    }
    // reaching condition
    if (i == maze.size() - 1 && j == maze[0].size() - 1)
        return 1;

    // l r u d
    vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int ways = 0;
    for (int it = 0; it < 4; it++)
    {
        int r = i + direction[it].first;
        int c = j + direction[it].second; // r=0 , c=-1
        if (r < 0 || c < 0 || r >= maze.size() || c >= maze[0].size() || maze[r][c] == 0)
            continue;
        if (check[r][c])
            continue;
        check[r][c] = true;
        ways += no_of_ways(maze, r, c, check);
        check[r][c] = false;
    }
    return ways;
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> maze(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> maze[i][j];
        }
    }
    vector<vector<bool>> check(r, vector<bool>(c, false));
    cout << no_of_ways(maze, 0, 0, check);
    return 0;
}