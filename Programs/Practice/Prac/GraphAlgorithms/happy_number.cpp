#include <bits/stdc++.h>
using namespace std;

//function to find the
//each digit square sum
int sumOfSquareDigits(int num)
{
    int sum=0;
    while(num>0)
      {
          int digit=num%10;
          sum+=digit*digit;
          num=num/10;
      }
    return sum;
}

//function to check the 
//given number is happy or
//not
bool isHappy(int num)
{
   set<int> st;
   while(num>1&&(st.find(num)==st.end()))
     {
        st.insert(num);
        num=sumOfSquareDigits(num);
     }

//if number becomes 1 then
//the number is happy
    if(num==1)
       return true;

 //else the numbe is not
 //happy
    else
      return false;
}
int main()
{
    int num=13;
    if(isHappy(num))
      cout<<"Happy Number\n";
    else
     cout<<"Not happy number\n";
}