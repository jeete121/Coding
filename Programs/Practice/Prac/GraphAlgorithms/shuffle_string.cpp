#include <bits/stdc++.h>
using namespace std;

//function to restore the string
//according to the indices given
string restoreString(string s, vector<int>& indices) 
{
    vector<char> v;
    v.resize(indices.size());
    for(int i=0;i<indices.size();i++)
             v[indices[i]]=s[i];
     string res="";
    for(int i=0;i<v.size();i++)
               res+=v[i];
     return res;
}
int main()
{
    string str="aiohn";
    vector<int> indices={3,1,4,2,0};
    str=restoreString(str,indices);
    cout<<str<<"\n";
    return 0;
}

