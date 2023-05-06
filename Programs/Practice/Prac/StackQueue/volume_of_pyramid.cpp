#include <bits/stdc++.h>
using namespace std;

//function to find the volume
//of rectangular base pyramid
double volumeOfPyramid(double length,double width,double height)
{
    //formula =1/3*areaofbase*height
    double volume=(length*width*height)/3;
    return volume;
}
int main()
{
    double length=5;
    double width=4;
    double height=12;
    double volume=volumeOfPyramid(length,width,height);
    cout<<"Volume is ";
    cout<<volume<<"\n";
    return 0;
}