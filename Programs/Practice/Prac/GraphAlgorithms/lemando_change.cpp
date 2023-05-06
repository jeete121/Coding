#include <bits/stdc++.h>
using namespace std;

//function to check for
//lemando change 
bool lemonadeChange(vector<int>& bills) 
 {
      int cnt5=0,cnt10=0;
        int flag=0;
      for(int i=0;i<bills.size();i++)
       {
          if(bills[i]==5)
                cnt5++;
          else if(bills[i]==10)
          {
              if(cnt5==0)
              {
                  flag=1;
                  break;
              }
              else
              {
                  cnt5--;
                  cnt10++;
              }
          }
          else if(bills[i]==20)
          {
              if(cnt5==0)
              {
                  flag=1;
                  break;
              }
             else if(cnt10==0 &&cnt5<3)
             {
                 flag=1;
                 break;
             }
            else if(cnt10==0)
            {
                
                cnt5-=3;
            }
             else if(cnt10>0)
             {
                 cnt10--;
                 cnt5--;
             }
          }
       }
    if(flag==0)
          return true;
        return false;
}

int main()
{
   vector<int> arr={5,5,5,10,20};
   if(lemonadeChange(arr))
     cout<<"true";
   else
    cout<<"false";
   
   return 0;
}