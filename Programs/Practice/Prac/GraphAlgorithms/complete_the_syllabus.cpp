#include <bits/stdc++.h>
using namespace std;

string completeSyllabus(int n, int a[])
{
    map<int, string> mp;
    mp[1] = "MONDAY";
    mp[2] = "TUESDAY";
    mp[3] = "WEDNESDAY";
    mp[4] = "THURSDAY";
    mp[5] = "FRIDAY";
    mp[6] = "SATURDAY";
    mp[7] = "SUNDAY";
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {

        sum += a[i];
    }
    if (n % sum == 0)
        n = sum;
    else
        n = n % sum;
    int ans;
    for (int i = 0; i < 7; i++)
    {
        n = n - a[i];
        if (n <= 0)
        {
            ans = i;
            break;
        }
    }
    return mp[ans + 1];
}
int main()
{

    int n = 2;
    int a[7] = {1, 1, 0, 0, 0, 0, 0};

    cout << completeSyllabus(n, a) << "\n";

    return 0;
}