#include <bits/stdc++.h>
using namespace std;

int caesarCipher(string A, string B)
{
    unordered_map<char, int> ump;
    for (int i = 0; i < 26; i++)
        ump['A' + i] = i;
    if (A == B)
        return 0;
    else
    {
        int k = 0;
        for (int j = 0; j <= 26; j++)
        {
            if ((ump[A[0]] + j) % 26 == ump[B[0]])
            {
                k = j;
                break;
            }
        }

        int flag = 0;
        for (int i = 1; i < B.size(); i++)
        {
            if ((ump[A[i]] + k) % 26 != ump[B[i]])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            return -1;
        else
            return k;
    }
}
int main()
{

    string A = "ABC", B = "DEF";

    cout << caesarCipher(A, B) << "\n";

    return 0;
}