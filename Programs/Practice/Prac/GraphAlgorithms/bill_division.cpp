#include <bits/stdc++.h>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b)
{
    int n = bill.size();
    int i, sum = 0, b_charged, b_actual;
    for (i = 0; i < n; i++)
        sum = sum + bill[i];
    b_charged = b;
    b_actual = (sum - bill[k]) / 2;
    if (b_charged == b_actual)
    {
        cout << "Bon Appetit\n";
    }
    else
    {
        cout << b_charged - b_actual;
    }
}
int main()
{
    int n = 4, k = 1;

    vector<int> bill = {3, 10, 2, 9};
    int b = 12;
    bonAppetit(bill, k, b);
    return 0;
}
