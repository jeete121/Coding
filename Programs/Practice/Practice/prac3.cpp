#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
void reverse(string &str,int n)
{
    stack<char> st;
    for(int i=0;i<n;i++)
      st.push(str[i]);
    int k=0;
    while(!st.empty())
     {
         str[k++]=st.top();
         st.pop();
     }
}
int main()
{
    string str="Techie Delight";
    reverse(str,str.size());
    cout<<str<<"\n";
}
