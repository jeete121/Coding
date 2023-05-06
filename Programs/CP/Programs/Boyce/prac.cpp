#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    unordered_set<int> st;
    for(int i=0;i<n;i ++)
     {
         cin>>x;
         st.insert(x);
     }
     for(auto it=st.begin();it!=st.end();it++)
        cout<<*it<<endl;
    return 0;
}