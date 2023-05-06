/*
Suffix Array of the string of lenght n
Time Complexity: O(nlog(n))
*/
/*
The algorithm requires O(nlogn) time and O(n) memory. However if we take
the size of the alphabet k into account, then it uses O((n+k)logn) time 
and O(n+k) memory.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> sort_cyclic_shifts(string s)
{
    int n=s.size();
    const int alphabet=256;
    /*
    At the beginning (in the 0-th iteration) we must sort the cyclic
    substrings of length 1, that is we have to sort all characters of
    the string and divide them into equivalence classes (same symbols 
    get assigned to the same class). This can be done trivially, for 
    example, by using counting sort. For each character we count how 
    many times it appears in the string, and then use this information
    to create the array p[]. After that we go through the array p[] and
    construct c[] by comparing adjacent characters.
    */

    vector<int> c(n),p(n),cnt(max(alphabet,n),0);
    for(int i=0;i<n;i++)
        cnt[s[i]]++;   //counting of all alphabets in string 
    for(int i=1;i<alphabet;i++)
       cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++)
       p[--cnt[s[i]]]=i;
    c[p[0]]=0;
    int classes=1;
    for(int i=1;i<n;i++)
      {
          if(s[p[i]]!=s[p[i-1]])
             classes++;
         c[p[i]]=classes-1;
      }
      /*
      Now we have to talk about the iteration step. Let's assume 
      we have already performed the k−1-th step and computed the values
      of the arrays p[] and c[] for it.
      To do this, note that the cyclic substrings of length 2^k consists 
      of two substrings of length 2^(k−1) which we can compare with each 
      other in O(1) using the information from the previous phase - the
      values of the equivalence classes c[]. Thus, for two substrings 
      of length 2k starting at position i and j, all necessary 
      information to compare them is contained in the pairs 
      (c[i], c[i+2^(k−1)]) and (c[j], c[j+2^(k−1)]).
      */
      vector<int> pn(n),cn(n);
      for(int h=0;(1<<h)<n;h++)
         {
             for(int i=0;i<n;i++)
               {
                   pn[i]=p[i]-(1<<h);
                   if(pn[i]<0)
                      pn[i]+=n;
               }
        fill(cnt.begin(),cnt.begin()+classes,0);
        for(int i=0;i<n;i++)
          cnt[c[pn[i]]]++;
        for(int i=1;i<classes;i++)
           cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--)
          p[--cnt[c[pn[i]]]]=pn[i];
        cn[p[0]]=0;
        classes=1;
        for(int i=1;i<n;i++)
           {
               pair<int,int> curr={c[p[i]],c[(p[i]+(1<<h))%n]};
               pair<int,int> prev={c[p[i-1]],c[(p[i-1]+(1<<h))%n]};
               if(curr!=prev)
                  classes++;
              cn[p[i]]=classes-1;
           }
           c.swap(cn);
         }
        return p;
}
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
int main()
{
    string s;
    cin>>s;
    vector<int> v=sort_cyclic_shifts(s);
    for(int i=0;i<v.size();i++)
       cout<<v[i]<<" ";
    return 0;
}