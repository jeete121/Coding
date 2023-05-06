#include <bits/stdc++.h>
using namespace std;
//function to find the volume 
//of prism
double volumePrism(double length,double width,double height)
{
    //base is rectangle
    double baseArea=length*width;
    //volume baseArea*height
    double volume =(baseArea*height);
    return volume;
}
int main()
{
  double length=4;
  double width=5;
  double height=6;
  double volume =volumePrism(length,width,height);
  cout<<"Volume of Prism is ";
  cout<<volume<<"\n";
  return 0;
}