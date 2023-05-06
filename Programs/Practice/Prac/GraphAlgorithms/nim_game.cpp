#include <bits/stdc++.h>
using namespace std;

bool canWinNim(int n) 
{
        if(n%4==0)
              return false;
        return true;
}

int main()
{
    int n=4;
    if(canWinNim(n))
      cout<<"true";
    else
      cout<<"false";

    return 0;
    
}