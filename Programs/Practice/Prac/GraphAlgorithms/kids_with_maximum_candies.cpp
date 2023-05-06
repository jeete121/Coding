#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, 
      int extraCandies) 
{
        vector<bool> res;
        int max1=INT_MIN;
        int n=candies.size();
        for(int i=0;i<n;i++)
              if(candies[i]>max1)
                    max1=candies[i];
       for(int i=0;i<n;i++)
        {
          if(candies[i]==max1) 
                res.push_back(true);
          else if(candies[i]+extraCandies>=max1)
                 res.push_back(true);
          else
              res.push_back(false);
        }
        return res;
}
int main()
{
 vector<int> candies ={2,3,5,1,3};
 int extraCandies = 3;
 vector<bool> extra= kidsWithCandies(candies,extraCandies);
 for(int i=0;i<extra.size();i++)
    cout<<extra[i]<<" ";
 return 0;
}

