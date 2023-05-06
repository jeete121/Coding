#include <bits/stdc++.h>
using namespace std;

int largElm=INT_MIN,largElmI=0,largElmJ=0;
int smallElm=INT_MAX,smallI=0,smallJ=0;
void searchingElement(vector<vector<int>> &arr)
{
    int m=0;
    int n=arr.size();
    if(n!=0)
      m=arr[0].size();
    for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
           {
               if(arr[i][j]>largElm)
                 {
                     largElm=arr[i][j];
                     largElmI=i;
                     largElmJ=j;
                 }
                if(arr[i][j]<smallElm)
                 {
                     smallElm=arr[i][j];
                     smallI=i;
                     smallJ=j;
                 }
           }

      }
    
}
int main()
{
    vector<vector<int>> arr= { { 6, 4, 2, 4 }, { 5, 6, 9, 2 },
                 { 5, 7, 2, 1 } };
    searchingElement(arr);
    cout<<"Largest element "<<largElm;
    cout<< " at ("<<largElmI<<","<<largElmJ<<")"<<"\n";
    cout<<"Smalast element "<<smallElm; 
    cout<<" at ("<<smallI<<","<<smallJ<<")";
}