#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

//function to find all the permutaions of the 
//given string
void permutations(string str,int l,int r)
{

    //base case if l and r same
    //then push the string into the 
    //vector of strings
    if(l==r)
      {
          ans.push_back(str);
      }
     else
     {
         for(int i=l;i<=r;i++)
          {

              swap(str[l],str[i]);
              permutations(str,l+1,r);
              swap(str[l],str[i]);

          }
     }
}
int main()
{
    string str="ABC";
    ans.clear();
    permutations(str,0,str.size()-1);
    for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<" ";
    return 0;
}