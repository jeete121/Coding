#include <bits/stdc++.h>
using namespace std;
void Swap(vector<int > &a,int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void permutations(vector<int> &a,int start,vector<vector< int >  > &results)
{
  if(start>=a.size())
    results.push_back(a);
  else
  {
       for(int i=start;i<a.size();i++)
         {
             Swap(a,start,i);
             permutations(a,start+1,results);
             Swap(a,start,i);
         }
  }
  
}
vector< vector<int> > permutations(vector<int> &a)
{
    vector< vector <int > > results;
    permutations(a,0,results);
    return results;
}
int main()
{
  int n,x;
  cout<<"Enter number of elements:\n";
  cin>>n;
  vector<int> v;
  for(int i=0;i<n;i++)
     {
         cin>>x;
         v.push_back(x);
     }
 vector< vector<int> > results=permutations(v);
 cout<<"Permuations are:\n";
 for(int i=0;i<results.size();i++)
    {
        for(int j=0;j<n;j++)
           cout<<results[i][j]<<" ";
        cout<<"\n";
    }
  return 0;
}