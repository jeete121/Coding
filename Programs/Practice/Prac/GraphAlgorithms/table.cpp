#include <bits/stdc++.h>
using namespace std;
//function which print
//table of given number
void printTable(int n)
{
    for(int i=1;i<=10;i++)
       cout<<i*n<<" ";
    
}
int main()
{
    int num=5;
    cout<<"Table is\n";
    printTable(num);
    return 0;
}