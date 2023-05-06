#include <bits/stdc++.h>
using namespace std;
//function to find the volume 
//of prism
double volumePrism(double base,double height)
{
    //base is square
    double baseArea=base*base;
    //volume baseArea*height
    double volume =baseArea*height;
    return volume;
}
int main()
{
  double base=4;
  double height=6;
  double volume =volumePrism(base,height);
  cout<<"Volume of Prism is ";
  cout<<volume<<"\n";
  return 0;
}