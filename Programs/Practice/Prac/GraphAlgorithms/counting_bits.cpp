#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int num)
{
        vector<int> res;
        for(int i=0;i<=num;i++)
        {
            int j=i;
            int cnt=0;
            while(j)
            {
                if(j&1)
                    cnt++;
                j=j>>1;
            }
            res.push_back(cnt);
        }
        return res;
}
int main()
{
    int n=5;
    vector<int> bits=countBits(n);
    for(int i=0;i<bits.size();i++)
       cout<<bits[i]<<" ";
    return 0;
}

