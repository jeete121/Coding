#include <bits/stdc++.h>
using namespace std;
void permutations(string prefix,string suffix,vector<string> &results)
{
    if(suffix.size()==0)
      results.push_back(prefix);
    else
    {
      for(int i=0;i<suffix.size();i++)
       permutations(prefix+suffix[i],suffix.substr(0,i)+suffix.substr(i+1,suffix.size()),results);
    }
    
}
vector<string> permutations(string str)
{
    vector<string> results;
    permutations("",str,results);
    return results;
}
int main()
{
    string str;
    cin>>str;
    vector<string> results=permutations(str);
    for(int i=0;i<results.size();i++)
       cout<<results[i]<<"\n";
    return 0;
}