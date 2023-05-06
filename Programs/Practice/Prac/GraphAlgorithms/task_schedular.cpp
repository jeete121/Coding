#include <bits/stdc++.h>
using namespace std;


int leastInterval(vector<char>& tasks, int n)
{
        int m=tasks.size();
        if(n==0)
               return m;
        if(m==0)
               return 0;
        vector<int> f(26,0);
        for(int i=0;i<m;i++)
                f[tasks[i]-'A']++;
        sort(f.begin(),f.end(),greater<int>());
        int i=0;
        while(i<26&&f[i]==f[0])
               i++;
        return max(m,(f[0]-1)*(n+1)+i);
}
int main()
{
    vector<char>tasks ={'A','A','A','B','B','B'};
    int  n = 2;
    cout<<leastInterval(tasks,n);
    return 0;
}
