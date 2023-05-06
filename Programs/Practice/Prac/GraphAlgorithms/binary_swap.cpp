#include <bits/stdc++.h>
using namespace std;

int binarySwap(string A, string B)
{
    if (A.size() != B.size())
        return -1;
    else
    {
        int cnt = 0;
        int cnt01 = 0, cnt02 = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != B[i])
                cnt++;
            if (A[i] == '0')
                cnt01++;
            if (B[i] == '0')
                cnt02++;
        }
        if (cnt01 != cnt02)
            return -1;
        else
            return cnt / 2;
    }
}
int main()
{
    string A = "1110", B = "1101";

    cout << binarySwap(A, B) << "\n";

    return 0;
}