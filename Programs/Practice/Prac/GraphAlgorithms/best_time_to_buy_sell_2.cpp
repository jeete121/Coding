#include <bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& prices) 
{
        if(prices.size()==0)
            return 0;
        int sell,buy,profit=0;
        int i=1,j=1;
        while(i<prices.size())
         {
            if(prices[i]<prices[i-1])
                  i++;
            else
            {
                j=i;
                break;
            }
        }
      if(i==prices.size())
            return 0;
      else
      {  
       buy=prices[i-1];
       sell=prices[i];
       if(j==prices.size()-1)
             return sell-buy;
       for(i=j+1;i<prices.size();i++)
        {
          if(prices[i]>sell)
             sell=prices[i];
          if(i==prices.size())
               profit=sell-buy;
         else
           {
            profit+=sell-buy;
            buy=prices[i];
             sell=prices[i];
           }
        }
      }
        return profit;
}

int main()
{ 
   vector<int> prices={7,1,5,3,6,4};
   cout<<maxProfit(prices);
   return 0;   
}
