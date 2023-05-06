#include <bits/stdc++.h>
using namespace std;
//Function to convert the decimal
//to binary
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
     //reverse the result
     reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int num=10;
    string binary=decimalToBinary(num);
    cout<<"Binary is ";
    cout<<binary<<"\n";
    return 0;
}