#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> &encoded, int first)
{
    vector<int> res;
    res.push_back(first);

    for (int i = 0; i < encoded.size(); i++)
    {
        int a = encoded[i];
        int b = res[i];
        int c; //res[i+1]
        //a=b^c

        //xor both sides by a
        //a^c=b

        //xor both sides by a
        //c=a^b;

        res.push_back(a ^ b);
    }
    return res;
}

int main()
{
    vector<int> encoded = {1, 2, 3};
    int first = 1;

    vector<int> arr = decode(encoded, first);

    cout << "[";

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}