#include <bits/stdc++.h>
using namespace std;


int tree[4000010];

//function to build the segment tree
void build(int node,int start,int end, int pos)
{

    //base case
    if(start==end)
        {
            tree[node]++;
            return;
            
        }
     int mid=start+(end-start)/2;

     //call for left 
      if(pos<=mid)
               build(2*node+1,start,mid,pos);

     //call for right
     else
       build(2*node+2,mid+1,end,pos);

      //update tree[node]
      tree[node]=tree[2*node+1]+tree[2*node+2];
        
}

//function to get the value in given
//range
int query(int index, int start, int end, int l, int r) 
{


     //base case completely overlap
        if(start>= l && end <= r)
            return tree[index];
        
    //base case out of range
        if(end < l ||start> r)
            return 0;
        
    int mid = start+(end-start)/2;
    //left answer
     int leftAns = query(2*index + 1, start, mid, l, r);
      
      //right answer
     int rightAns = query(2*index + 2, mid + 1, end, l, r);
        
    return leftAns + rightAns;
}
int createSortedArray(vector<int>& instructions) 
{
      int MAXN=1e5+1;
        int ans=0;
        int MOD=1e9+7;
        for(auto x : instructions)
        {
              int mincount=query(0,0,MAXN,0,x-1);
               int maxcount=query(0,0,MAXN,x+1,MAXN);
            ans=(ans+min(mincount,maxcount))%MOD;
            build(0,0,MAXN,x);
        }
        return ans;
}

int main()
{
   vector<int> instructions ={1,5,6,2};
   cout<<createSortedArray(instructions);
   return 0;
}