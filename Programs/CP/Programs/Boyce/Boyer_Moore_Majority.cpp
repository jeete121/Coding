#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++)
       cin>>arr[j];
    int m,i=0;
    for(int j=0;j<n;j++)
       {
           if(i==0)
             {
                 m=arr[j];
                 i=1;
             }
             else
             {
                 if(m==arr[j])
                    i++;
                 else
                   i--;
                 
             }
             
       }
    cout<<m<<endl;
}