#include <bits/stdc++.h>
using namespace std;
void printTriangle(int r) 
{
   int b = 10;
   for (int i = 1; i <= r; i++) 
     {
      for (int j = 0; j <= b; j++)
        {
                cout<<" ";
        }
            b = b - 1;
       for (int k = 1; k <= i; k++) 
          {
                cout<<"* ";
            }
            cout<<"\n";
        }
}
int main()
{
  int n = 10;
  printTriangle(n);
}

