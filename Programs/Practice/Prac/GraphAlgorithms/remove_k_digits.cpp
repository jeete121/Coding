#include <bits/stdc++.h>
using namespace std;

void remove(string num,int k,string &res)
{
    //base case
     if(k==0)
        {
             res.append(num);
             return;
     }
    int n=num.size();

    //if k is greater than n then
    //return 
    if(n<=k)
        return;
    int minIndex=0;
    for(int i=1;i<=k;i++)
       {
         if(num[i]<num[minIndex])
          {
                minIndex=i;
          }
       }
     res.push_back(num[minIndex]);
     string  new_string=num.substr(minIndex+1,n-minIndex);
    remove(new_string,k-minIndex,res);
       
}

//function to remove k digits from the number
string removeKdigits(string num, int k) 
{
        string res="",ans="";
        remove(num,k,res);
        if(res.size()==0)
              ans+="0";
        int i=0;
        while(res[i]=='0')
               i++;
        for(int j=i;j<res.size();j++)
                ans+=res[j];
        if(ans.size()==0)
              ans+="0";
        return ans;
}
int main()
{
   string num = "1432219";
   int k = 3;
   cout<<removeKdigits(num,k);
   return 0;
}

