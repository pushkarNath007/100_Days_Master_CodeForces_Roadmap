#include <bits/stdc++.h>
using namespace std;
int convert(string s)
{
    return stoi(s);
}
bool isOperand(string s)
{

    if (s != "+" && s != "-" && s != "*" && s != "/")
        return true;
    return false;
}
int evaluate(vector<string> &arr)
{
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (isOperand(arr[i]))
        {
            // its a operand
            s.push(convert(arr[i]));
        }
        else
        {
            // if its a operator
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();
            if (arr[i] == "+")
            {
                s.push(left + right);
            }
            else if (arr[i] == "-")
            {
                s.push(left - right);
            }
            else if (arr[i] == "*")
            {
                s.push(right * left);
            }
            else if (arr[i] == "/")
            {
                s.push(left / right);
            }
        }
    }
    return s.top();
}
int main()
{
    vector<string> arr = vector<string>{"-8", "3", "/"};

    cout << evaluate(arr) << endl;
    return 0;
}