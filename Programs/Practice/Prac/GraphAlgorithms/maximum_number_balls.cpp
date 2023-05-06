#include <bits/stdc++.h>
using namespace std;

int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int temp = n % 10;
        sum += temp;
        n = n / 10;
    }
    return sum;
}
int countBalls(int lowLimit, int highLimit)
{

    map<int, int> mp;
    for (int i = lowLimit; i <= highLimit; i++)
    {
        int sum = digitSum(i);

        mp[sum]++;
    }
    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans = max(ans, it->second);
    }
    return ans;
}

int main()
{
    int lowLimit = 1, highLimit = 10;

    cout << countBalls(lowLimit, highLimit);

    return 0;
}