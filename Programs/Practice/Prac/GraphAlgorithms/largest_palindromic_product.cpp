#include <bits/stdc++.h>
using namespace std;

//function to check for
//palindrome
bool isPalindrome(int n)
{
    int num=n;
    int rev=0;
    while(n>0)
     {
         rev=rev*10+n%10;
         n=n/10;
     }
    if(rev==num)
       return true;
    return false;
}
int main()
{
    vector<int> res;

    //store all palindrome of 
    //number which are product of
    //2 three digit numbers
    for(int i=100;i<1000;i++)
      {
          for(int j=100;j<1000;j++)
           {
               int x=i*j;
               if(isPalindrome(x))
                  res.push_back(x);
           }
      }
    int len=res.size();

    //sort them 
    sort(res.begin(),res.end());
    int n=101110;
    int ans;

    //find the gretest number
    //which is less than n and 
    //palindrome           
    for(int i=len-1;i>=0;i--)
       {
          if(res[i]<n)
            {
               ans=res[i];
               break;
            }
              
       }
     cout<<ans<<"\n";
    return 0;
}
