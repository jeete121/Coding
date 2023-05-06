#include <bits/stdc++.h>
using namespace std;
//Function to convert from binary to decimal
int binaryToDecimal(string s)
{
    int res=0;
    int n=s.size();
    for(int i=0;i<n;i++)
      {
          if(s[i]=='1')
            res=res+pow(2,(n-i-1));
      }
    return res;
}
int main()
{
    string str="1101";
    int decimal=binaryToDecimal(str);
    cout<<"Decimal is ";
    cout<<decimal<<"\n";
    return 0;
}