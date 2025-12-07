#include <bits/stdc++.h>
using namespace std;

// technique
//  find function finds from left and
// apple will always come before app
// because  app is its  substr
// and app will always come after apple
//  so we know if we get apple  till 
//  SO APPLE STRING IS PART OF ANSWER 
// SO STORED IT AND CHANGE YOUR STR TO PART 
// AFTER APPLE LAST WORD  and PART BEFORE APPLE WORD
// EG ->  BCAPPLEBAPPYT
// HERE->  APPLE IS STORED PART OF ANSWER
//  EG-> STR BECOMES  BCBAAPYT BEFORE AND AFTER  APPLE STRING END 
// NOW CHECK IF APPLE NOT THERE THEN CHECK FOR 
// APP NOW IF FOUND REVOME FROM STR AND SEND STR TO FUNCTION
// AT END STR WILL BE WITHOUT APP ALSO 
// THEN RETURN IT AND ADD TO SUBSTR WHICH WE SAVED

string skipASubstr2(string str, string skip, string notskip)
{
    auto sk=str.find(skip);
    if(sk==string::npos){
        return str;
    }
   string substr="";
   auto it=str.find(notskip);
   if(it!=string::npos){
     substr=str.substr(it,notskip.size());
     string sub1=str.substr(0,it);
     string sub2 = str.substr(it + notskip.size(), str.size() - it + notskip.size());
     str=sub1+sub2;
   }
   else {
        auto it=str.find(skip);
        if(it!=string::npos){
            string substr1=str.substr(0,it);
            string substr2= str.substr(it + skip.size(), str.size() - it + skip.size()); 
            str=substr1+substr2;
           
        }
   }
   substr += skipASubstr2(str, skip, notskip);
   return substr;
}
int main()
{
    string str, skip, notskip;
    cin >> str >> skip >> notskip;
    // skipASubstr(str, skip, skip.size());
    
    cout<<skipASubstr2(str, skip, notskip);
  
    return 0;
}