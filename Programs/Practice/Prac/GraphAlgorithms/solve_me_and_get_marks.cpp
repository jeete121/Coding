#include <bits/stdc++.h>
using namespace std;

int main()
{
    int noMercy = 6;
    vector<int> marksArray = {100, 9, 10, 15, 1};
    sort(marksArray.begin(), marksArray.end());
    int noWorry = 0;
    for (int i = 0; i < marksArray.size(); i++)
    {
        if (i == 0)
        {
            if (marksArray[0] + noMercy < marksArray[1])
                noWorry++;
        }
        else if (i == marksArray.size() - 1)
        {
            if (marksArray[marksArray.size() - 1] - noMercy > marksArray[marksArray.size() - 2])
                noWorry++;
        }
        else if (marksArray[i] - noMercy > marksArray[i - 1] && marksArray[i] + noMercy < marksArray[i + 1])
            noWorry++;
    }
    cout << marksArray.size() - noWorry << " students need to worry!\n";
    cout << noWorry << " students should relax!\n";

    return 0;
}
