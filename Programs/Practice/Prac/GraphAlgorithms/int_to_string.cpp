#include <bits/stdc++.h>
using namespace std;

//function to convert the 
//integer to string
string intToString(int num)
{
    //string stream 
   stringstream str1;
   //put the value into str
    str1 << num;
    //convert into string format
    string str = str1.str();
    return str;
}
int main()
{ 
   int num=1320;
   //call the function to convert
   //the into string 
   string str=intToString(num);
   // print the string 
    cout << str;
    return  0;
}