#include <bits/stdc++.h>
using namespace std;

bool isOneBitCharacter(vector<int> &bits)
{
    int n = bits.size(), i = 0;
    if (n == 1)
        return true;
    int flag = 0;
    while (i < n)
    {
        if (bits[i] == 1)
        {
            i = i + 2;
            if (i == n)
            {
                flag = 1;
                break;
            }
        }
        else
        {
            i++;
        }
    }
    if (flag == 1)
        return false;
    return true;
}
int main()
{
    vector<int> bits = {1, 0, 0};
    if (isOneBitCharacter(bits))
        cout << "true";
    else
        cout << "false";
    return 0;
}