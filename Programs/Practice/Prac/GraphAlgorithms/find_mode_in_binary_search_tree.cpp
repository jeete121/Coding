#include <bits/stdc++.h>
using namespace std;

//struct for treenode
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
map<int, int> mp;
int max1 = INT_MIN;
void dfs(TreeNode *root)
{
    if (root == NULL)
        return;
    dfs(root->left);
    mp[root->data]++;
    max1 = max(max1, mp[root->data]);
    dfs(root->right);
}
vector<int> findMode(TreeNode *root)
{
    vector<int> res;
    mp.clear();
    dfs(root);
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == max1)
            res.push_back(it->first);
    }

    return res;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    vector<int> modes = findMode(root);

    cout << "[";

    for (int i = 0; i < modes.size(); i++)
    {
        cout << modes[i];
        if (i != modes.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}