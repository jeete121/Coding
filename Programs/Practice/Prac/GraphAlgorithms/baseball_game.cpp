#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string> &ops)
{
    vector<int> scores;
    int n = ops.size();

    for (auto i : ops)
    {

        if (i == "+")
        {
            int len = scores.size();
            int x = scores[len - 1];
            int y = scores[len - 2];
            scores.push_back(x + y);
        }
        else if (i == "D")
        {
            int len = scores.size();
            int prev = scores[len - 1];
            scores.push_back(2 * prev);
        }

        else if (i == "C")
        {
            scores.pop_back();
        }
        else
        {
            scores.push_back(stoi(i));
        }
    }
    int sum = 0;
    for (int i = 0; i < scores.size(); i++)
    {
        sum += scores[i];
    }
    return sum;
}

int main()
{
    vector<string> ops = {"5", "2", "C", "D", "+"};

    cout << calPoints(ops);

    return 0;
}