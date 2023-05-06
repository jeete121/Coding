#include <bits/stdc++.h>
using namespace std;
//function to find mod of a
//given number with some number
int getModulus(int num,int division)
{
    return num-division*(num/division);
}
int main()
{
    int num=100;
    int division=8;
    int modulus= getModulus(num,division);
    cout<<"Modulus is ";
    cout<<modulus<<"\n";
    return 0;
}