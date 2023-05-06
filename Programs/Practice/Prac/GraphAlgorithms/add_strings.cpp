#include <bits/stdc++.h>
using namespace std;

//function to add two strings
string addStrings(string num1, string num2)
{

    //find the lenths of both strings
    int n = num1.size(), m = num2.size();

    //if first is empty
    if (n == 0)
        return num2;

    //if second is empty
    if (m == 0)
        return num1;
    string res = "";
    int carry = 0;
    if (n == m)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            int x = carry + num1[i] - '0' + num2[i] - '0';
            int y = x;
            x = x % 10;
            //convert into string and add it into the
            //result
            res = to_string(x) + res;
            carry = (y) / 10;
        }
        if (carry > 0)
        {
            int x = carry;
            //convert into string and add it into the
            //result
            res = to_string(x) + res;
        }
    }
    else if (n > m)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            int x = carry + num1[n - m + i] - '0' + num2[i] - '0';
            int y = x;
            x = x % 10;
            //convert into string and add it into the
            //result
            res = to_string(x) + res;
            carry = (y) / 10;
        }
        for (int i = n - m - 1; i >= 0; i--)
        {
            int x = carry + num1[i] - '0';
            int y = x;
            x = x % 10;
            //convert into string and add it into the
            //result
            res = to_string(x) + res;
            carry = (y) / 10;
        }
        if (carry > 0)
        {
            int x = carry;
            //convert into string and add it into the
            //result
            res = to_string(x) + res;
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            int x = carry + num1[i] - '0' + num2[m - n + i] - '0';
            int y = x;
            x = x % 10;
            //convert into string and add it into the
            //result
            res = to_string(x) + res;
            carry = (y) / 10;
        }
        for (int i = m - n - 1; i >= 0; i--)
        {
            int x = carry + num2[i] - '0';
            int y = x;
            x = x % 10;
            //convert into string and add it into the
            //result
            res = to_string(x) + res;
            carry = (y) / 10;
        }
        if (carry > 0)
        {
            int x = carry;

            //convert into string and add it into the
            //result
            res = to_string(x) + res;
        }
    }
    return res;
}

int main()
{
    string A = "123";
    string B = "234";
    cout << addStrings(A, B);
    return 0;
}