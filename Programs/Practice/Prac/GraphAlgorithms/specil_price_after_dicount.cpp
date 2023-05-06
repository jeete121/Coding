#include <bits/stdc++.h>
using namespace std;


//function to find the final
//price after dicount 
vector<int> finalPrices(vector<int>& prices) 
{
       stack<int> st;
       int n=prices.size();
       if(n==0)
             return prices;

      //push last into the stack
      st.push(prices[n-1]);
     //iterate till we reah to 0
      for(int i=n-2;i>=0;i--)
      {
          //while stack is not empty and st top is
          //greater then current price then pop
          while(!st.empty()&&st.top()>prices[i])
                 st.pop();

          //if stack is not empty then update new price
          //and push into the stack
         if(!st.empty())
         {
             int x=st.top();
             st.push(prices[i]);
             prices[i]=prices[i]-x;
         }

         //else push into the stack without discount
          else
               st.push(prices[i]);
         
      }
    return prices;
}
int main()
{
   vector<int> prices ={8,4,6,2,3};
   vector<int> special=finalPrices(prices);
   for(int i=0;i<special.size();i++)
      cout<<special[i]<<" ";
   return 0;
}

