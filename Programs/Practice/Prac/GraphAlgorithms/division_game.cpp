#include <bits/stdc++.h>
using namespace std;

bool divisorGame(int N) 
{
        if(N%2==0)
              return true;
        return false;
}

int main()
{
    int n=10;
    if(divisorGame(n))
      cout<<"true";
    else
      cout<<"false";

    return 0;
}