#include <bits/stdc++.h>
using namespace std;

void permutation(string str, string output, int i)
{    
    // abc
    //  str= "a"  output = "c"
    if (i == output.size())
    {
        cout << str << " ";
        return;
    }
    for (int j = 0; j <= str.size(); j++)
    {
        string pre = str.substr(0, j);
        string post = str.substr(j, str.size() - j);
        permutation(pre + output[i] + post, output, i + 1);
    }
}
int main()
{
    string output;
    cin >> output;
    permutation("",output, 0);
    return 0;
}