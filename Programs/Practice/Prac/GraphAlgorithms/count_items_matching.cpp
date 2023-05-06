#include <bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>> &items,
                 string ruleKey, string ruleValue)
{

    int count = 0;

    for (int i = 0; i < items.size(); i++)
    {
        string typei = items[i][0];
        string colori = items[i][1];
        string namei = items[i][2];

        if (ruleKey == "type" && ruleValue == typei)
            count++;
        else if (ruleKey == "color" && ruleValue == colori)
            count++;
        else if (ruleKey == "name" && ruleValue == namei)
            count++;
    }
    return count;
}
int main()
{
    vector<vector<string>> items = {{"phone", "blue", "pixel"},
                                    {"computer", "silver", "lenovo"},
                                    {"phone", "gold", "iphone"}};
    string ruleKey = "color", ruleValue = "silver";

    cout << countMatches(items, ruleKey, ruleValue);

    return 0;
}