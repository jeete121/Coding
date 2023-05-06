#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 2;
    int b = 10;
    int output = 0;
    int c = b - a;
    if (c < 0)
        c = c * -1;
    output = output + (c / 5);
    c = c % 5;
    output = output + (c / 2);
    c = c % 2;
    output = output + c;

    cout << output << "\n";

    return 0;
}
