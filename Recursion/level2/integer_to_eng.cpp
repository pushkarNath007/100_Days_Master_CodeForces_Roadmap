#include <bits/stdc++.h>
using namespace std;

string int_to_english(int n)
{
    if (n == 0)
        return "Zero";
    vector<pair<int, string>> arr = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Fourty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};
    // 1234
    string ans = "";
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (n >= arr[i].first)
        {
            // cout << n << " " << arr[i].first << endl;
            if (arr[i].first >= 100)
            {
                string ans2 = int_to_english(n / arr[i].first);
                ans += ans2;
                ans += arr[i].second; //  1234 = one thousand
                // now digit skip we will do outside if condition
                // cout << ans << endl;
            }
            else
            {
                ans += arr[i].second; //  34 = thirty first then digit skip
                // cout << ans << endl;
            }

            if (n % arr[i].first != 0)
            {
                string ans3 = int_to_english(n % arr[i].first);

                ans += ans3;
                // cout << ans << endl;
            }
            // here your last value n never become 0 means this loop will run  and never stop so  you need to send your answer inside loop
            return ans;
        }
    }

    return ans;
}
int main()
{
    int num;
    cin >> num;
    cout << int_to_english(num);
    return 0;
}