#include <bits/stdc++.h>
using namespace std;
char firstNonRepeating(string str)
{
    int n=str.size();
    char ans='#';
    for(int i=0;i<n;i++)
      {
          ans=str[i];
          int j=i+1;
          int flag=0;
          for(j=i+1;j<n;j++)
            {
               if(str[j]==ans)
                  {
                      flag=1;
                      break;
                  }
            }
         if(flag==0)
            return ans;

      }
      return ans;
}
int main()
{
    string str="Hi Hello World";
    char first=firstNonRepeating(str);
    cout<<"First Non repeating is ";
    cout<<first<<"\n";
    return 0;
}