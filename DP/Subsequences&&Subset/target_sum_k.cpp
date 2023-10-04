#include <bits/stdc++.h>
using namespace std;

void printing(vector<vector<int>> &arr, int r, int target)
{
   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j <= target; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
}
int findTargetSumWays(vector<int> &nums, int target)
{
   int r = nums.size() + 1;
   // cout << r << endl;
   vector<vector<int>> arr(r, vector<int>(target + 1, 0));
   for (int i = 0; i < r; i++)
   {
      arr[i][0] = 1;
   }

   printing(arr, r, target);

   for (int i = 1; i < r; i++)
   {
      for (int j = nums[i - 1]; j <= target; j++)
      {
         arr[i][j] = arr[i - 1][j] + arr[i - 1][j - nums[i - 1]];
      }
   }

   cout << endl
        << endl;
   printing(arr, r, target);
   return arr[r - 1][target];
}
int main()
{
   int n, k;
   cin >> n >> k;

   vector<int> nums(n, 0);
   for (int i = 0; i < n; i++)
      cin >> nums[i];
   findTargetSumWays(nums, k);
   return 0;
}