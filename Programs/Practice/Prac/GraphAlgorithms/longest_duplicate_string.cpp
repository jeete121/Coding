#include <bits/stdc++.h>
using namespace std;


vector<int> power;
string ret;
int prime=10000007;

//rabincarp function for string matching
string rabincarp(string &s,int &k)
{
        if(k==0)
              return "";
        long long int hash=0;
        unordered_map<int,vector<int> > mp;
        for(int i=k-1;i>=0;i--){
            hash=(hash%prime+(power[k-1-i]*(s[i]-'a'+1))%prime)%prime;
        }
        int i=0,j=k-1;
        mp[hash]=vector<int>(1,0);
        bool flag=0;
        while(j<s.size()){
            hash=(hash%prime-((power[k-1]*(s[i]-'a'+1))%prime)+prime)%prime;
            hash=(hash%prime*26%prime)%prime;
            i++;
            j++;
            if(j<s.size()){
                hash=(hash%prime+((power[0]*(s[j]-'a'+1))%prime))%prime;
                if(mp.find(hash)!=mp.end()){
                    for(auto ind:mp[hash]){
                        if(s.substr(ind,k)==s.substr(i,k))
                           return s.substr(ind,k);
    
                    }
                    mp[hash].push_back(i);
                }
                else{
                    mp[hash]=vector<int>(1,i);
                }
            }
        }
        return "";
}

string longestDupSubstring(string S) 
{
        int n=S.size();
        power.resize(n+1);
        power[0]=1;
        for(int i=1;i<=n;i++){
            power[i]=(26*power[i-1])%prime;
        }
        int low=0,high=n;
        string ans="";
        while(low<=high){
            int mid=low+(high-low)/2;
            string x=rabincarp(S,mid);
            if(x.size()>0)
            {
                if(x.size()>ans.size())
                    ans=x;
               low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
}
int main()
{
    string s = "banana";
    cout<<longestDupSubstring(s);
    return 0;
}
