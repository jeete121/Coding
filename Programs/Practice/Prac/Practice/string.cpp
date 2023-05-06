#include <bits/stdc++.h>
using namespace std;
int fun1(vector<pair<int,string>> &v,string b,int l)
{
   for(int i=0;i<v.size();i++)
     {
         if(v[i].first>=l)
           {
               if(v[i].second==b)
                   return v[i].first;
           }
     }
   return -1;
}
int fun2(vector<pair<int,string>> &v,string b,int l)
 {
     for(int i=0;i<v.size();i++)
       {
           if(v[i].first>=l)
             {
                 if(v[i].second==b)
                      return v[i].first;
                 else
                 {
                     string x=v[i].second;
                     if(x.size()>=b.size())
                       {
                           int j;
                        for(j=0;j<=x.size()-b.size();j++)
                          {
                              int flag=true;
                              for(int k=j;k<=j+b.size()-1;k++)
                                 {
                                     if(x[j+k]!=b[k])
                                        {
                                            flag=false;
                                            break;
                                        }
                                 }
                            if(flag==true)
                                return v[i].first+j;
                          }
                       }
                 }
                 
             }
       }
       return -1;
 }
int main()
{
   int t;
   cin>>t;
   while(t--)
     {
         string A,B;
         char C;
         int l;
         cin>>ws;
         getline(cin,A);
         cin>>ws;
         cin>>B;
         cin>>C;
         cin>>l;
         vector<pair<int,string>> v;
         int i=0,j;
         while(i<A.size())
         {
             while(i<A.size()&&A[i]==' ')
                i++;
             j=i;
             string str="";
             while(i<A.size()&&A[i]!=' ')
                {
                    str+=A[i];
                    i++;
                }
            
            v.push_back({j,str});
         }
       if(C=='Y')
         {
             int x=fun1(v,B,l);
             if(x>=0)
                cout<<x<<"\n";
             else
             {
                 cout<<"Goodbye Watson.\n";
             }
             
         }
        else
        {
            int x=fun2(v,B,l);
            if(x>=0)
                cout<<x<<"\n";
            else
            {
               cout<<"Goodbye Watson.\n";
            }
            
        }
        
     }
    return 0;
}