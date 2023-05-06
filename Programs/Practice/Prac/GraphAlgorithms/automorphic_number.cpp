#include <bits/stdc++.h>
using namespace std;

//function to check the
//automorphic number
bool checkAutomorphicNumber(int num)
{
    //square of given number
    int squre=num*num;

    //length of given number
    int length=log10(num)+1; 
    //find mod of given number based on no 
    //of digits
    int mod=pow(10,length);

    //get last digits based on mod;
    int lastNum=squre%mod;
    //check number with last lastNum
    if(lastNum==num)
       return true;
    else
        return false;

}
int main()
{
    int num=5;
    if(checkAutomorphicNumber(num))
      cout<<"Number is automorphic\n";
    else 
      cout<<"Number is not automorphic\n";
    return 0;
}