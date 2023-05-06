#include <bits/stdc++.h>
using namespace std;
int tree[4010];

//function to build the seqment tree
void build(int node,int start,int end,int arr[])
{

    //base case
    if(start==end)
     {
         tree[node]=arr[start];
         return ;
     }
     //find the mid point
     int mid=(start+end)/2;

     //call for left half
     build(2*node,start,mid,arr);

     //call for right half
     build(2*node+1,mid+1,end,arr);
    
    //merger the both halves
     tree[node]=tree[2*node]+tree[2*node+1];
}

//funtion to query the given queries
int query(int node,int start,int end,int l,int r)
{
    //if out of bound
    if(start>r||end<l)
       return 0;

     //if completely in the range
    if(start>=l&&end<=r)
      return tree[node];
     //find mid point
    int mid=(start+end)/2;

    //call for left half
    int p1=query(2*node,start,mid,l,r);

    //call for right half
    int p2=query(2*node+1,mid+1,end,l,r);

    //return the sum of both the half
    return p1+p2;
}

int main()
{
    
    int arr[6];

    //array is 1 based indexing
    arr[1]=2;
    arr[2]=3;
    arr[3]=1;
    arr[4]=6;
    arr[5]=5; 
    int n=5;
    build(1,1,n,arr);
    int q=3;
   cout<<query(1,1,n,1,4)<<"\n";
   cout<<query(1,1,n,2,3)<<"\n";
   cout<<query(1,1,n,1,5)<<"\n";
   return 0;
}