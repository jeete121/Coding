#include <bits/stdc++.h>
using namespace std;
//function to find the prime
//factor of the given number
vector<int> primeFactor(int num)
{
    vector<int> prime;
    //if numner is divisible by 2
    while(num%2==0)
      {
          prime.push_back(2);
          num=num/2;
      }
    //now iterate from i=3 and skip all
    //even number
    for(int i=3;i*i<=num;i+=2)
      {
          if(num%i==0)
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
    cout<<"Prime factors are\n";
    for(int i=0;i<prime.size();i++)
       cout<<prime[i]<<" ";
    return 0;
}
//Time Complexity: O(sqrt(n))
//Space Complexity:O(1)
