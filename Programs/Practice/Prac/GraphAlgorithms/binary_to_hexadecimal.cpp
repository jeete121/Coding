#include  <bits/stdc++.h>
using namespace std;
//Function to convert binary to 
//hexadecimal
string binaryToHexadecimal(string s)
{
    int n=s.size();
    int m=n%4;
    if(m!=0)
       m=4-m;
    reverse(s.begin(),s.end());
    //make the string length factor of 4
    while(m--)
       s+='0';
    string ans="";
    reverse(s.begin(),s.end());
    //new length of string
    n=s.size();
    for(int i=0;i<=n-4;i+=4)
      {
          int res=0;
           for(int j=0;j<4;j++)
              {
                 if(s[i+j]=='1')
                    res=res+pow(2,3-j);
              }
            if(res==16)
               ans+="10";
            else
            {
              m=res%16;
              if(res<=9)
               ans+=to_string(res);
              else
                ans+='A'+res%10;
            }
               
      }  
    return ans;
}
int main()
{
    string str="11010";
    string hexadecimal=binaryToHexadecimal(str);
    cout<<"Hexadecimal is ";
    cout<<hexadecimal<<"\n";
    return 0;
}