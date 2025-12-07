#include <bits/stdc++.h>
using namespace std;

int countFLipsCount(string pwd)
{
    int count = 0;
    if (pwd.size() == 1)
        return count;
    for (int i = 1; i < pwd.size() - 1; i += 2)
    {
        if (pwd[i] != pwd[i - 1])
            count++;
        else if (i + 1 <= pwd.size() - 1 && pwd[i] != pwd[i + 1])
            count++;
    }
    return count;
}
int main()
{
    string pwd;
    cin >> pwd;
    cout << countFLipsCount(pwd);
    return 0;
}