#include <bits/stdc++.h>
using namespace std;

//function to convert the
//fahrenheit to celcius
double fahrenheitToCelcius(double fahrenheit)
{
    //formula: ((f+40)/1.8)-40=c
    double celcius=((fahrenheit+40)/1.8)-40;
    return celcius;
}
int main()
{
    double fahrenheit=37.76;
    double celcius=fahrenheitToCelcius(fahrenheit);
    cout<<"Celcius is ";
    cout<<celcius<<"\n";
    return 0;
}