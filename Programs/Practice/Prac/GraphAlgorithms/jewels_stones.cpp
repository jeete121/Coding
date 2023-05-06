#include <bits/stdc++.h>
using namespace std;

//function to find the number
//of stones and jewels
int numJewelsInStones(string J, string S) 
{
      int n=J.size();
      int m=S.size();
      int f1[26]={0};
      int f2[26]={0};
      for(int i=0;i<n;i++)
      {
          if(J[i]>='A'&&J[i]<='Z')
                f1[J[i]-'A']++;
          else
              f2[J[i]-'a']++;
      }
        int f3[26]={0};
        int f4[26]={0};
      for(int i=0;i<m;i++)
        {
              if(S[i]>='A'&&S[i]<='Z')
                f3[S[i]-'A']++;
          else
              f4[S[i]-'a']++;
          
        }
      int sum=0;
      for(int i=0;i<26;i++)
       {
         if(f1[i]>0)
             sum+=f3[i];   
          if(f2[i]>0)
              sum+=f4[i];
       }
        return sum;
}

int main()
{
    string jewels = "aA";
    string stones = "aAAbbbb";
    cout<<numJewelsInStones(jewels,stones);
    return 0;
}

