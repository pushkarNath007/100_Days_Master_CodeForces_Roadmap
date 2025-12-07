#include <bits/stdc++.h>
using namespace std;

void printing(vector<vector<int>> &matrix)
{
    cout << endl
         << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j])
            {
                cout << "Q  ";
            }
            else
                cout << "*  ";
        }
        cout << endl;
    }
}
bool isSafe(vector<vector<int>> &matrix, int r, int c)
{
    // i need to check whether i can place my queen at curr position or not
    //      0 0 0 0
    //      0 0 i 0
    //      0 0 0 0
    // vector<pair<int, int>>move={{-1,-1},{0,-1},{1,-1}};

    int j = c - 1;
    int i = r;
    // left straight
    while (j >= 0)
    {
        if (matrix[i][j])
        {
            return false;
        }
        j--;
    }
    j = c - 1;
    i = r - 1;
    // left up
    while (j >= 0 && i >= 0)
    {
        if (matrix[i][j])
        {
            return false;
        }
        j--;
        i--;
    }
    // left down
    i = r + 1;
    j = c - 1;
    while (j >= 0 && i < matrix.size())
    {
        if (matrix[i][j])
            return false;
        i++;
        j--;
    }
    return true;
}
void nQueen(vector<vector<int>> &matrix, int c)
{
    // base case
    if (c >= matrix[0].size())
    {
        printing(matrix);
        return;
    }

    // one solution
    for (int r = 0; r < matrix.size(); r++)
    {
        if (isSafe(matrix, r, c))
        {
            matrix[r][c] = 1;
            nQueen(matrix, c + 1);
            matrix[r][c] = 0;
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << 0;
        return 0;
    }
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    nQueen(matrix, 0);
    // cout << matrix[0][2];
    return 0;
}