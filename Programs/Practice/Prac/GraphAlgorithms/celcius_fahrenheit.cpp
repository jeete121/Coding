#include <bits/stdc++.h>
using namespace std;

//function to convert celcius
//to fahrenheit
double celciusToFahrenheit(double celcius)
{
    //formula : ((c+40)*1.8)-40=f
    double fahrenenheit=((celcius+40)*1.8)-40;
    return fahrenenheit;
}
int main()
{
    double celcius=3.2;
    double faherenheit=celciusToFahrenheit(celcius);
    cout<<"Faherenheit is ";
    cout<<faherenheit<<"\n";
    return 0; 
}