#include <bits/stdc++.h>
using namespace std;

bool canThreePartsEqualSum(vector<int> &arr)
{

    //find sum of all elements of the array
    int summ = accumulate(arr.begin(), arr.end(), 0);

    //variable to hold the part sum
    int part = 0;

    //variable to hold the count of
    //parts
    int count = 0;

    //if sum is divisible by 3
    if (summ % 3 == 0)
    {

        //iterate for all elements of the array
        for (int x : arr)
        {
            //update part sum
            part += x;

            //if part sum is total sum /3
            if (part == (summ / 3))
            {
                //update count
                count++;

                //reset part sum
                part = 0;
            }
        }
    }
    return count >= 3;
}

int main()
{
    vector<int> arr = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};

    if (canThreePartsEqualSum(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}