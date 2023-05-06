//Range power  query between l and r power=f*f*arr[i];
#include <bits/stdc++.h>
#define BLK 1000
using  namespace std;
struct query
{
    int l,r,i;
};
query Q[200001];
long long  int arr[200001] , ans[200001];
long long int fre[1000001];
long long int  power=0;
bool cmp(query a,query b)
{
   if(a.l/BLK!=b.l/BLK)
      return a.l/BLK<b.l/BLK;
    return a.r<b.r;
}
void add(int pos)
{
 	long long int  cnt = fre[arr[pos]];
	fre[arr[pos]]++;
	power -= (cnt * cnt) * arr[pos];
    cnt++;
	power += (cnt * cnt) * arr[pos];
}
void remove(int  pos)
{
	long long int cnt = fre[arr[pos]];
	fre[arr[pos]]--;
	power -= (cnt * cnt) * arr[pos];
    cnt--;
	power += (cnt * cnt) * arr[pos];
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  int n,q;
  cin>>n>>q;
  for(int i=0;i<n;i++)
    cin>>arr[i];
	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i = i;
        Q[i].l--;
        Q[i].r--;
	}
   sort(Q,Q+q,cmp);
   int ML=0,MR=-1;
   for(int i=0;i<q;i++)
    {
        int  L=Q[i].l;
        int R=Q[i].r;
        while(ML > L)
		  {
              ML-- ;
              add(ML);
          }
          while(MR<R)
            {
                MR++;
                add(MR);
            }
         while(ML<L)
           {
               remove(ML);
               ML++;
             
           }
         while(MR>R)
           {
               remove(MR);
               MR--;
           }
           ans[Q[i].i]=power;
    }
    for(int i=0;i<q;i++)
       cout<<ans[i]<<"\n";
    return 0;
}