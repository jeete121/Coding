#include <bits/stdc++.h>
using namespace std;

//comparator used for sorting
static bool cmp(pair<int, pair<string, int>> a, pair<int, 
              pair<string, int>> b)
{
    if (a.first == b.first)
    {
        return a.second.first < b.second.first;
    }

    return a.first > b.first;
}

//function to find the top k
//frquent strings
vector<string> topKFrequent(vector<string> &words, int k)
{
    map<string, int> mp;
    for (int i = 0; i < words.size(); i++)
        mp[words[i]]++;
    vector<pair<int, pair<string, int>>> v;
    for (int i = 0; i < words.size(); i++)
    {
        v.push_back({mp[words[i]], {words[i], i}});
    }
    sort(v.begin(), v.end(), cmp);
    set<string> st;
    vector<string> res;
    for (int i = 0; i < v.size() && k > 0; i++)
    {

        if (st.find(v[i].second.first) == st.end())
        {
            res.push_back(v[i].second.first);
            k--;
        }
        st.insert(v[i].second.first);
    }
    return res;
}

int main()
{

    vector<string> strs = {"i", "love", "link", "i", "love", "coding"};
    int k = 2;
    vector<string> freq = topKFrequent(strs, k);
    cout << "[";
    for (int i = 0; i < freq.size() - 1; i++)
        cout << freq[i] << ", ";
    cout << freq[freq.size() - 1] << "]";
    return 0;
}