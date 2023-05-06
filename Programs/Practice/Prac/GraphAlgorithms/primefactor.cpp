#include <bits/stdc++.h>
using namespace std;
//function to find prime factors
//of given number
vector<int> primeFactor(int num)
{
    vector<int> prime;
    for(int i=2;i*i<=num;i++)
     {
         while(num%i==0)
            {
                prime.push_back(i);
                num=num/i;
            }
     }
     if(num>1)
       prime.push_back(num);
    return prime;
}
int main()
{
  int num=24;
  vector<int> prime=primeFactor(num);
  for(int i=0;i<prime.size();i++)
     cout<<prime[i]<<" ";
  return 0;
}
//Time complexity: O(sqrt(n))