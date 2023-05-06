#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    int  octal=62;
    string binary=octalToBinary(octal);   
    cout<<"Binary is ";
    cout<<binary<<"\n";
    return 0;
}