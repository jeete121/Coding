#include <bits/stdc++.h>
using namespace std;
//Function to cinvert from 
//decimal to binary
string decimalToBinary(int n)
{
    //varibale to store the final
    //result
    string res="";
    while(n>0)
     {
         //if n%2==0 then appen 0
         if(n%2==0)
            res+='0';
        //if n%2==1 then appen 1
        else 
           res+='1';
        n=n/2;
     }
     if(res.size()<3)
       res+='0';
     //reverse the result
     reverse(res.begin(),res.end());
    
    return res;
}
//Function to convert from octal
//to binary
string octalToBinary(int octal)
{
   string binary="";
   while(octal>0)
    {
        int mod=octal%10;
        if(mod==0)
           binary="000"+binary;
        else
          binary= decimalToBinary(mod)+binary;
        octal=octal/10;
    }  
  return binary;
}
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
string octalToHexadecimal(int octal)
{
    //convert octal to binary
    string binary=octalToBinary(octal);
    //convert binary to hexadecimal
    string hexadecimal=binaryToHexadecimal(binary);
    return hexadecimal;
}
int main()
{
    int octal=540;
    string hexadeicmal=octalToHexadecimal(octal);
    cout<<"Hexadeicmal is ";
    cout<<hexadeicmal<<"\n";
    return 0;
}