#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
        unordered_map<string,vector<string>> ump;
        for(int i=0;i<strs.size();i++)
        {
            string x=strs[i];
            sort(x.begin(),x.end());
            ump[x].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto it=ump.begin();it!=ump.end();it++)
               res.push_back(it->second);
        return res;
 }
int main()
{
  vector<string> strs ={"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>> res=groupAnagrams(strs);
  cout<<"[";
  for(int i=0;i<res.size();i++)
    {
        cout<<"[";
        for(int j=0;j<res[i].size();j++)
           {
               cout<<res[i][j];
               if(j!=res[i].size()-1)
                  cout<<",";
           }
        cout<<"]";
        if(i!=res.size()-1)
          cout<<",";
    }
    cout<<"]";
}
