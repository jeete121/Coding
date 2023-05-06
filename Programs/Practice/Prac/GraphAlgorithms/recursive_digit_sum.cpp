#include <bits/stdc++.h>
using namespace std;

//function to find the sum of
//digits of a number
long long int digitSum(long long int n)
{
    long long int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}
int main()
{
    string s = "9875";

    long long int k = 4;

    long long int sum = 0;
    for (long long int i = 0; i < s.size(); i++)
    {
        sum += s[i] - '0';
    }
    sum = sum * k;
    while (sum >= 10)
    {
        sum = digitSum(sum);
    }
    cout << sum << "\n";
    return 0;
}
