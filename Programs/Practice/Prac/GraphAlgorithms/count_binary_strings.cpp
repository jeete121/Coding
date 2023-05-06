#include <bits/stdc++.h>
using namespace std;

int countBinarySubstrings(string s)
{
    //if string is empty then return 0
    if (s.empty())
    {
        return 0;
    }

    bool lastZero = false;
    if (s[0] == '0')
        lastZero = true;

    int zero_count = 0;
    int one_count = 0;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {

        //if zero
        if (s[i] == '0')
        {
            //if last zero is false then
            //reset zero count
            if (lastZero == false)
            {
                zero_count = 0;
            }

            //increment zero count
            zero_count++;

            //if one count is greater than 0
            //then decrement one count and update
            //the count
            if (one_count > 0)
            {
                --one_count;
                count++;
            }

            lastZero = true;
        }

        //if one
        else
        {
            if (lastZero == true)
            {
                one_count = 0;
            }
            one_count++;
            if (zero_count)
            {
                --zero_count;
                count++;
            }
            lastZero = false;
        }
    }

    return count;
}

int main()
{
    string str = "00110011";

    cout << countBinarySubstrings(str);

    return 0;
}