#include <iostream>
using namespace std;

int countingValleys(int steps, string path)
{

    int no = 0, i = 0, j = 0;
    for (i = 0; i < steps; i++)
    {
        if (path[i] == 'U')
        {
            j = j + 1;
            if (j == 0)
                no++;
        }
        else
        {
            j = j - 1;
        }
    }
    return no;
}

int main()
{
    long int n = 8;

    string s = "UDDDUDUU";
    cout << countingValleys(n, s);
    return 0;
}
