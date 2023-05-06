#include <bits/stdc++.h>
using namespace std;
//function to find factors of
//the given number
vector<int> factorOfNumber(int num)
{
  vector<int> factor;
  for(int i=1;i*i<=num;i++)
      {
          //num%i==0 then  i is a factor of num
          if(num%i==0)
             {
                 //if num/i and i both are same
                 if(num/i==i)
                   factor.push_back(i);
                //if num/i and i both are different
                 else
                 {
                     factor.push_back(i);
                     factor.push_back(num/i);
                 }
             }
      }
   return factor;
}
int main()
{
   int num=24;
   vector<int> factor=factorOfNumber(num);
   for(int i=0;i<factor.size();i++)
       cout<<factor[i]<<" ";
   return 0;
}
//Time complexity: O(sqrt(n))