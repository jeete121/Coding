#include <bits/stdc++.h>
using namespace std;

//function to sort the string
//according to the frequency
string frequencySort(string s)
{
    unordered_map<char, int> ump;

    //count the frequency of each chararcters
    for (int i = 0; i < s.size(); i++)
        ump[s[i]]++;

    //max priority queue
    priority_queue<pair<int, char>> pq;

    //push into the priority queue
    for (auto p : ump)
        pq.push({p.second, p.first});
    string res = "";

    //make the string by 
    //adding the charcters whose frequency is more
    //first then the characters whose frequecy is less
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        
        while (p.first--)
            res += p.second;
    }
    return res;
}

int main()
{
    string str = "tree";
    cout << frequencySort(str);
    return 0;
}