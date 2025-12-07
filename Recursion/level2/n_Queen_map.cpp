#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> left1;
unordered_map<int, bool> rightToLeft;
unordered_map<int, bool> leftToRight;

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
    // cout << " c -> " << c << " r -> " << r << endl;
    if (left1[r] == true)
    {
        // cout << " r== true r -> " << r << " c -> " << c << endl;
        return false;
    }
    if (leftToRight[(matrix.size() - 1) + c - r] == true)
    {
        // cout << " (matrix.size() - 1) + c - r == true r -> " << r << " c -> " << c << endl;
        return false;
    }
    if (rightToLeft[r + c] == true)
    {
        // cout << " c+r == true r -> " << r << " c -> " << c << endl;
        return false;
    }
    return true;
}
void nQueen(vector<vector<int>> &matrix, int c)
{   //      0 1 2 3     r    c-r  r+c
    //   0  0 0 Q 0     0=0  3=0  0=0
    //   1  Q 0 0 0     2=0  2=0  3=0
    //   2  0 0 0 Q     3=0  1=0  4=0
    //   3  0 Q 0 0     1=0  4=0  3=0
    //                  1=1  2=1  1=1
    //                  3=1  1=1  4=1
    //                  0=1  5=1  2=1
    //
    // base case
    if (c >= matrix[0].size())
    {
        printing(matrix);
        return;
    }
    for (int r = 0; r < matrix.size(); r++)
    {
        if (isSafe(matrix, r, c))
        {
            matrix[r][c] = 1;
            left1[r] = true;
            leftToRight[(matrix.size() - 1) + c - r] = true;
            rightToLeft[r + c] = true;
            // cout << "queen r-> " << r << " c -> " << c << endl;
            // cout << "map -> r "
            //      << "-> " << r << " -> " << left1[r] << " ,(matrix.size() - 1) + c - r  -> " << (matrix.size() - 1) + c - r << " -> " << leftToRight[(matrix.size() - 1) + c - r] << " , r + c ->  " << r + c << " -> " << rightToLeft[r + c] << endl;
            nQueen(matrix, c + 1);
            matrix[r][c] = 0;
            left1[r] = false;
            leftToRight[(matrix.size() - 1) + c - r] = false;
            rightToLeft[r + c] = false;
            // cout << endl
            //      << " after function return " << endl;
            // cout << "map -> r "
            //      << "-> " << r << " -> " << left1[r] << " ,(matrix.size() - 1) + c - r  -> " << (matrix.size() - 1) + c - r << " -> " << leftToRight[(matrix.size() - 1) + c - r] << " , r + c ->  " << r + c << " -> " << rightToLeft[r + c] << endl;
        }
    }
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