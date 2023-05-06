#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
struct Node
{
    int ar[3];
};
Node tree[400004];
int lazy[400004];
void build(int node,int start,int end)
{
    if(start==end)
      {
          //Multiple of three 0%3,1%3,2%3;
         tree[node].ar[0]=1;
         tree[node].ar[1]=0;
         tree[node].ar[2]=0;
         return;
      }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node].ar[0]=tree[2*node].ar[0]+tree[2*node+1].ar[0];
    tree[node].ar[1]=tree[2*node].ar[1]+tree[2*node+1].ar[1];
    tree[node].ar[2]=tree[2*node].ar[2]+tree[2*node+1].ar[2];
}
void shift(int node)
{
    int a=tree[node].ar[2];
    tree[node].ar[2]=tree[node].ar[1];
    tree[node].ar[1]=tree[node].ar[0];
    tree[node].ar[0]=a;
}

int query(int node , int start , int end , int l , int r)
{
	if(lazy[node] != 0)
	{
		int add = lazy[node];
		lazy[node] = 0;
		if(start != end)
		{
			lazy[2*node] += add;
			lazy[2*node+1] += add;
		}
		add %= 3;
		for(int i=0;i<add;i++)
		{
			shift(node);
		}
	}
	
	if(start > r || end < l) {
		return 0;
	}
	
	if(start >= l && end <= r)
	{
		return tree[node].ar[0];
	}
	
	int mid = (start + end) / 2;
	int p1 = query(2*node , start , mid , l ,r);
	int p2= query(2*node+1 , mid+1 , end , l ,r);
	
	return p1+p2;
}
void update(int node , int start , int end, int l , int r)
{
	if(lazy[node] != 0)
	{
		int add = lazy[node];
		lazy[node] = 0;
		if(start !=end)
		{
			lazy[2*node] += add;
			lazy[2*node+1] += add;
		}
		add %= 3;
		for(int i=0;i<add;i++)
		{
			shift(node);
		}
	}
	if(start > r || end < l) return;
	
	if(start >= l && end <= r)
	{
		shift(node);
		if(start != end)
		{
			lazy[2*node]++;
			lazy[2*node+1]++;
		}
		return;
	}
	
	int mid = (start + end) / 2;
	update(2*node , start , mid , l , r);
	update(2*node+1 , mid+1 , end ,l , r);
	
	tree[node].ar[0] = tree[2*node].ar[0] + tree[2*node+1].ar[0];
	tree[node].ar[1] = tree[2*node].ar[1] + tree[2*node+1].ar[1];
	tree[node].ar[2] = tree[2*node].ar[2] + tree[2*node+1].ar[2];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,q,a,b,c;
	cin>>n>>q;
	build(1 , 1 , n);
	
	while(q--)
	{
		cin>>c>>a>>b;
		a++;
		b++;
		if(c==0)
		{
			update(1,1,n,a,b);
		}
		else
		{
			cout<<query(1,1,n,a,b)<<"\n";
		}
	}
}
