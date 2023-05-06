#include <bits/stdc++.h>
using namespace std;

//function to check that we
//can place the flowers such that no
//two flowers are adjacent 
bool canPlaceFlowers(int flowerbed[], int n,int m)
{
  //count the no of current placed flower
   int cnt=0;
   int flag=0;

   //if their is no flower to put
   //return true
   if(n==0)
      return true;
 
 //if only one element and only 
 //one flower to put then return true
 //if flowerbed[0]=0
  if(m==1&&n==1&&flowerbed[0]==0)
      return true;

//iterate for all the index
  for(int i=0;i<m;i++)
     {

      //if we are at first position
        if(i==0)
          {
              //if first is empty and second also empty
              //the increment cnt and make flowerbed[i]=1
           if(flowerbed[i]==0&&i+1<m&&flowerbed[i+1]==0)
             {
                cnt++;
                flowerbed[i]=1;
             }
           }

         //if we are at the last position of the array
         //if second last is empty and last is empty 
         //increment the count ans make the last as 1
         else if(i==m-1)
         {
             if(i-1>=0&&flowerbed[i-1]==0&&flowerbed[i]==0)
               {
                 cnt++;
                 flowerbed[i]=1;
              }
         }
    //else we check left of position and right of position
     else
         {
        //if left ,right and current index is 0 then
        //increment the count and make the current index as 1
         if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0)
          {
              cnt++;
              flowerbed[i]=1;
           }
          }
      
      //if count becomes n break out of loop
      //and  make flag as 1
      if(cnt==n)
            {
                flag=1;
                break;
            }
      }
    
    //if flag remain 0 then return false
    if(flag==0) 
        return false;
    //else return true
    else
       return true;
}
int main()
{
  int flowerbed[]={1,0,0,0,1,0,0,0,1};
  int n=3;
  int m=sizeof(flowerbed)/sizeof(flowerbed[0]);
  if(canPlaceFlowers(flowerbed,n,m))
    cout<<"Given all flower can be place\n";
  else
    cout<<"Given all flowers can not be place\n";
  return 0;
  
}