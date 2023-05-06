#include <bits/stdc++.h>
using namespace std;

int getLucky(string s, int k)
{

    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - 'a' + 1;
        while (num > 0)
        {
            sum += num % 10;
            num = num / 10;
        }
    }
    k--;
    while (k > 0 && sum > 0)
    {
        int newSum = 0;

        while (sum > 0)
        {
            newSum += sum % 10;
            sum = sum / 10;
        }
        sum = newSum;
        k--;
    }
    return sum;
}

int main()
{
    string s = "iiii";
    int k = 1;

    cout << getLucky(s, k) << "\n";

    return 0;
}