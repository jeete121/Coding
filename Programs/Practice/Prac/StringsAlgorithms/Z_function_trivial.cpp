/*
For a string str[0..n-1], Z array is of same length as string.
An element Z[i] of Z array stores length of the longest substring 
starting from str[i] which is also a prefix of str[0..n-1]. 
The first entry of Z array is meaning less as complete string is 
always prefix of itself.

 Time Complexity: O(n^2)

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> z_function_trivial(string s)
{
    int n=s.size();
    vector<int> Z(n,0);
    for(int i=1;i<n;i++)
      {
          while(i+Z[i]<n&&s[Z[i]]==s[i+Z[i]])
              Z[i]++;
      }
    return Z;
}
int main()
{
    string s;
    cin>>s;
    vector<int> v=z_function_trivial(s);
    for(int i=0;i<v.size();i++)
       cout<<v[i]<<" ";
   return 0;
}