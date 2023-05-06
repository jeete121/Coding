#include <bits/stdc++.h>
using namespace std;

//function to convert integer to 
//roman number
string intToRoman(int num)
 {
    string res="";
     while(num>0)
     {
        if(num>=1000)
        {
            int x=num/1000;
            for(int i=0;i<x;i++)
                 res+='M';
            num=num%1000;
        }
        else if(num>=900)
        {
           res+='C';
            res+='M';
            num=num%100;
        }
       else if(num>=500)
       {
           int x=num/100;
           res+='D';
           for(int i=6;i<=x;i++)
               res+='C';
           num=num%100;
       }
   else  if(num>=400)
    {
        res+='C';
        res+='D';
        num=num%100;
    }
        else  if(num>=100)
         {
             int x=num/100;
             for(int i=1;i<=x;i++)
                  res+='C';
            num=num%100;
         }
        else if(num>=90)
        {
            res+='X';
            res+='C';
            num=num%10;
        }
       else  if(num>=50)
        {
            int x=num/10;
            res+='L';
            for(int i=6;i<=x;i++)
                 res+='X';
           num=num%10;
        }
        else if(num>=40)
        {
            res+='X';
            res+='L';
            num=num%10;
        }
      else if(num>=10)
      {
          int x=num/10;
          for(int i=1;i<=x;i++)
                res+='X';
          num=num%10;
      }
     else if(num==9)
     {
         res+='I';
         res+='X';
         num=0;
     }
     else if(num>=5)
     {
         int x=num/5;
         res+='V';
         for(int i=6;i<=num;i++)
               res+='I';
         num=0;
     }
    else if(num==4)
    {
        res+='I';
        res+='V';
        num=0;
    }
    else 
    {
        for(int i=1;i<=num;i++)
              res+='I';
        num=0;
    }
    }
      return res;  
}
int main()
{
    int num=58;
    string roman=intToRoman(num);
    cout<<roman<<"\n";
    return 0;
}