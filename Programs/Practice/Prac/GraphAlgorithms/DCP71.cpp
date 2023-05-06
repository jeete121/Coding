#include <bits/stdc++.h>
using namespace std;

int rand7()
{
    return rand() % 7 + 1;
}

int rand5()
{

    int x = rand7();
    if (x < 6)
        return x;
    return rand5();
}

int main()
{

    cout << rand5() << " ";
    return 0;
}