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

vector<string> no_of_ways(vector<vector<int>> &maze, int i, int j, vector<vector<bool>> &check, string &str)
{
    // cout << endl
    //      << i << " " << j << " ";
    // outer boundary condition
    if (i < 0 || j < 0 || i >= maze.size() || j >= maze[0].size())
    {
        vector<string> ans;
        return ans;
    }
    // maze going condition if 1 can go otherwise cant go
    if (!maze[i][j])
    {
        vector<string> ans;
        return ans;
    }
    // reaching condition
    if (i == maze.size() - 1 && j == maze[0].size() - 1)
    {
        vector<string> ans;
        ans.push_back(str);
        return ans;
    }

    // l r u d
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<char> dirname = {'u', 'd', 'l', 'r'};
    // int ways = 0;
    vector<string> ans;
    for (int it = 0; it < 4; it++)
    {
        int r = i + direction[it].first;
        int c = j + direction[it].second; // r=0 , c=-1
        if (r < 0 || c < 0 || r >= maze.size() || c >= maze[0].size() || maze[r][c] == 0)
            continue;
        if (check[r][c])
            continue;
        check[r][c] = true;
        str.push_back(dirname[it]);
        vector<string> temp_ans = no_of_ways(maze, r, c, check, str);
        str.pop_back();
        ans.insert(ans.end(), temp_ans.begin(), temp_ans.end());
        check[r][c] = false;
    }
    return ans;
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
    if (maze[0][0] == 0)
    {
        cout << "No path exists";
        return 0;
    }
    string str = "";
    vector<vector<bool>> check(r, vector<bool>(c, false));
    vector<string> ans = no_of_ways(maze, 0, 0, check, str);
    if (!ans.size())
    {
        cout << "No path exists";
        return 0;
    }
    for (auto it : ans)
        cout << it << " ";
    return 0;
}