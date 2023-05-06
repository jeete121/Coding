#include <bits/stdc++.h>
using namespace std;

//function to convert the
//string to integer
int  stringToint(string  str)
{
    //string stream 
   stringstream str1 (str);
    //varible to hold the integer value
     int num=0;
    str1>>num;
    return num;
}
int main()
{ 
   string  str="1320";
   //call the function to convert
   //the into string 
   int  num=stringToint(str);
   // print the integer value
    cout << num;
    return  0;
}