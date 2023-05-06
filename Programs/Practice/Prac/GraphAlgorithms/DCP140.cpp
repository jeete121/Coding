#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums)
{

    int bitwise = 0;

    for (int num : nums)
    {
        bitwise ^= num;
    }

    int diff = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((bitwise >> i) & 1) == 1)
        {
            diff = (1 << i);
            break;
        }
    }

    vector<int> result(2);
    for (int num : nums)
    {
        if ((diff & num) != 0)
        {
            result[0] ^= num;
        }
        else
            result[1] ^= num;
    }
    return result;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 10, 2, 6, 10};

    vector<int> twonum = singleNumber(arr);

    cout << "[";
    cout << twonum[0] << ", " << twonum[1];
    cout << "]";

    return 0;
}