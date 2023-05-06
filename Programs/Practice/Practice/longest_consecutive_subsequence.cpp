#include <bits/stdc++.h>
using namespace std;
int longest_consecuive_subusequence(vector<int> &v)
{
    unordered_set<int> uset;
    for(int i=0;i<v.size();i++)
         uset.insert(v[i]);
    int max_len=1;
    for(int e:v)
    {
        if(uset.find(e-1)==uset.end())
        {
          int len=1;
          while(uset.find(e+len)!=uset.end())
               len++;
          max_len=max(max_len,len);
        }
    }
    return max_len;
}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    int a;
    for(int i=0;i<n;i++)
    {
      cin>>a;
      v.push_back(a);
    }
   int res=longest_consecuive_subusequence(v);
   cout<<res<<endl;
}
