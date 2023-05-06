#include <bits/stdc++.h>
using namespace std;

//function to add two binary strings
string addBinary(string a, string b)
{
      int n=a.size(),m=b.size();
      int i=n-1,j=m-1;

      //initialize the carry
      int carry=0;
      string res="";

      //iterate till the one or both string ends
      //in reverse order
      while(i>=0&&j>=0)
      {
          int x=a[i]-'0';
          int y=b[j]-'0';
          int p=x+y+carry;

          //store the cuurent into the
          //string are  by taking mod 
          //with 2
          res=to_string(p%2)+res;

          //update carry
          carry=p/2;
          i--;
          j--;
          
      }
     //if first string is left
     while(i>=0)
     {
         int x=a[i]-'0';
         int p=x+carry;
         res=to_string(p%2)+res;
         carry=p/2;
         i--;
     }

     //if second string is left
   while(j>=0)
     {
         int x=b[j]-'0';
         int p=x+carry;
         res=to_string(p%2)+res;
         carry=p/2;
       j--;
     }
    //if their is carry
    if(carry)
          res=to_string(carry)+res;
    
           return res;
}
int main()
{
    string a="11";
    string b="1";
    cout<<addBinary(a,b);
    return 0;
}