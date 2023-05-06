// #include <bits/stdc++.h>
// using namespace std;

#include <bits/stdc++.h>
using namespace std;

void nthprimedigitsnumber(long long int n)
{

    long long int len = 1;

    long long int prev_count = 0;
    while (true)
    {

        long long int curr_count = prev_count + pow(3, len);

        if (prev_count < n && curr_count >= n)
            break;

        len++;

        prev_count = curr_count;
    }

    for (long long int i = 1; i <= len; i++)
    {

        for (long long int j = 1; j <= 3; j++)
        {

            if (prev_count + pow(3, len - i) < n)
                prev_count += pow(3, len - i);

            else
            {
                if (j == 1)
                    cout << "2";
                else if (j == 2)
                    cout << "3";
                else if (j == 3)
                    cout << "5";
                break;
            }
        }
    }
    cout << endl;
}

int main()
{
    long long int num = 1000000000000000000;

    nthprimedigitsnumber(num);
    return 0;
}