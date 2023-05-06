#include <bits/stdc++.h>
using namespace std;

int rand5()
{
    return rand() % 5 + 1;
}

int rand7()
{
    int x = 5 * rand5() + rand5() - 5;
    if (x < 22)
    {
        return x % 7 + 1;
    }
    return rand7();
}
int main()
{

    cout << rand7() << " ";

    return 0;
}