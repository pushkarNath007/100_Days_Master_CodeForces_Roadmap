#include <bits/stdc++.h>
using namespace std;

string remove_chr(string &str, char ch, int i)
{
   // HERE YOU SUBSITUTE THE ACTUALY STRING CHAR AND SIZE SO IF REMOVED 
   //  A CHAR FROM ACTUAL STRING  FUNCTION CALL WITH SAME I BECAUSE ITS NEXT VALUE
   //  IS NOW IN SAME I 
   //  ELSE  I+1  FUNCTION 
   
   //  base condition
   if (i == str.size())
   {
      // if (str[i] == ch)
      // {
      //    str = str.substr(0, i);
      // }
      return str;
   }


   if (str[i] == ch)
   {
      string substr1 = str.substr(0, i);

      string substr = str.substr(i + 1, str.size() - 1 - i);
      str = substr1 + substr;
      return remove_chr(str, ch, i);
   }
   else
      return remove_chr(str, ch, i + 1);
}
void remove_chr1(string str, char chr, int i, string &ans)
{

   if (i == str.size())
      return;
   if (str[i] != chr)
   {
      ans += str[i];
   }
   remove_chr1(str, chr, i + 1, ans);
}
string remove_str3(string &str, char ch, int i)
{
   if (i == str.size())
   {
      return "";
   }
   string ans = "";
   if (str[i] != ch)
   {
      ans += str[i];
   }
   ans += remove_str3(str, ch, i + 1);
   return ans;
}
int main()
{
   string str;
   char ch;
   cin >> str >> ch;
   cout << remove_chr(str, ch, 0) << endl;
   string ans = "";
   remove_chr1(str, ch, 0, ans);
   cout<<remove_str3(str,ch,0);
   cout << ans << " ";
   return 0;
}