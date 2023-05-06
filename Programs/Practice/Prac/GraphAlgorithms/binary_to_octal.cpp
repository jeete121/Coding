#include <bits/stdc++.h>
using namespace std;
//Function to convert binary
//to octal
string binaryToOctal(string s)
{
    int n=s.size();
    int m=n%3;
    if(m!=0)
      m=3-m;
    reverse(s.begin(),s.end());
    while(m--)
       s+='0';
    //new length of string 
    n=s.size();
    string ans="";
    reverse(s.begin(),s.end());
    for(int i=0;i<=n-3;i+=3)
     {
         int res=0;
         for(int j=0;j<3;j++)
          {
              if(s[i+j]=='1')
                 res=res+pow(2,2-j);
          }
        ans+=to_string(res);
     }
    return ans;

}
int main()
{
    string str="11010";
    string octal=binaryToOctal(str);
    cout<<"Octal is ";
    cout<<octal<<"\n";
    return 0;
}
//Time Complexity: O(n)
//Space Complexity:O(1)