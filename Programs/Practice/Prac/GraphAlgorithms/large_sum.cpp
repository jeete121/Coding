#include <bits/stdc++.h>
using namespace std;

//function to add two strings
string addStrings(string a,string b)
{
    int n=a.size(),m=b.size();
    int i=n-1,j=m-1;
    int carry=0;
    string ans="";
    while(i>=0||j>=0)
      {
          int x=0,y=0;
          if(i>=0)
             x=a[i]-'0';
          if(j>=0)
             y=b[j]-'0';
        i--;
        j--; 
        ans=to_string((x+y+carry)%10)+ans;
        carry=(x+y+carry)/10;
      }
    if(carry>0)
      ans=to_string(carry)+ans;
    return ans;
}
int main()
{
    int n=5;
    vector<string> str={"37107287533902102798797998220837590246510135740250",
     "46376937677490009712648124896970078050417018260538",
     "74324986199524741059474233309513058123726617309629",
     "91942213363574161572522430563301811072406154908250",
     "23067588207539346171171980310421047513778063246676"};
    string ans=str[0];
    for(int i=1;i<n;i++)
      ans=addStrings(ans,str[i]);
    cout<<ans.substr(0,10);
    return 0;
}