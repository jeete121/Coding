#include <bits/stdc++.h>
using namespace std;

//function to partition the string
vector<int> partitionLabels(string S) 
{
       int f[26]={0};
         vector<int> res;
        if(S.size()==0)
               return res;
        for(int i=0;i<S.size();i++) 
               f[S[i]-'a']=i;
       
        int x=0,y=0;
        for(int i=0;i<S.size();i++)
        {
            x=max(x,f[S[i]-'a']);
            if(i==x)
            {
                  res.push_back(i-y+1);
                  y=i+1;
            }
                   
        }
      return res;
}
int main()
{
    string S = "ababcbacadefegdehijhklij";
    vector<int> part=partitionLabels(S);
    for(int i=0;i<part.size();i++)
       cout<<part[i]<<" ";
    return  0;
}

