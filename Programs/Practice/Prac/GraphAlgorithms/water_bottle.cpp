#include <bits/stdc++.h>
using namespace std;

//function to count the number of bottles

int numWaterBottles(int numBottles, int numExchange) 
{
    int ans=numBottles;
    int x=ans;
    while(x>=numExchange)
       {
          ans+=x/numExchange;
       
         int y=x%numExchange;
         x=x/numExchange;
         x=x+y;
       }
        return ans;
}
int main()
{
    int numBottles=9;
    int numExchange=3;
    cout<<numWaterBottles(numBottles,numExchange);
    return 0;
}
