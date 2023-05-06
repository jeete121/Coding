#include <bits/stdc++.h>
using namespace std;

//function to format the
//amount into currency format
// eg. 1234 output= 1,234

string currencyFormat(long long int amount)
{
   string ans="";
   string x="";
   long long int cnt=0;

   //iterate till the amount
   //becomes 0
   while(amount>0)
      {
         x=to_string(amount%10)+x;
        cnt++;
        amount=amount/10;

        //if count becomes 3
        if(cnt==3)
          {

              //if amount is not equal to 0
              //then insert ',' +x+ans
              if(amount!=0)
                ans=','+x+ans;
            
            //else x+ans
              else
               ans=x+ans;
              
             //reset x
              x="";
              //reset count
              cnt=0;
          }
        
      }
     //if thier is something left
     //then add this 
    ans=x+ans; 

    //retunr the final answer
    return ans; 
}
int main()
{
   long long int amount =1392431860;
   
    string format_string=currencyFormat(amount);
    cout<<format_string<<"\n";
    return 0;
}