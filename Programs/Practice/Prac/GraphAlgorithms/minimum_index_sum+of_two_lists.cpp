#include <bits/stdc++.h>
using namespace std;

vector<string> findRestaurant(vector<string> &list1,
                              vector<string> &list2)
{
    vector<string> restaurants;
    unordered_map<string, int> restaurantsList;

    for (int i = 0; i < list1.size(); i++)
        restaurantsList[list1.at(i)] = i;

    int minIndex = INT_MAX;
    for (int i = 0; i < list2.size(); i++)
    {
        if (restaurantsList.find(list2.at(i)) != restaurantsList.end())
        {
            if (minIndex > i + restaurantsList.at(list2.at(i)))
            {
                minIndex = i + restaurantsList.at(list2.at(i));

                restaurants.clear();
                restaurants.push_back(list2.at(i));
            }

            else if (minIndex == i + restaurantsList.at(list2.at(i)))
            {
                restaurants.push_back(list2.at(i));
            }
        }
    }

    return restaurants;
}

int main()
{
    vector<string> list1 = {"Shogun", "Tapioca Express",
                            "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines",
                            "Hungry Hunter Steakhouse", "Shogun"};

    vector<string> res = findRestaurant(list1, list2);

    cout << "[";

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}