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
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        this->data = x;
        this->left = left;
        this->right = right;
    }
};

map<int, vector<TreeNode *>> vis;

vector<TreeNode *> allPossibleFBT(int N)
{

    vector<TreeNode *> res;

    // Even N is of no use,
    if (!(N & 1))
        return res;

    // Base Cases
    vis[0] = {}, vis[1] = {new TreeNode(0)};

    if (vis.count(N) >= 1)
        return vis[N];

    for (int i = 1; i < N; i += 2)
    {

        vector<TreeNode *> left1 = allPossibleFBT(i);
        vector<TreeNode *> right1 = allPossibleFBT(N - i - 1);

        for (auto x : left1)
        {
            for (auto y : right1)
            {
                TreeNode *temp = new TreeNode(0, x, y);
                res.push_back(temp);
            }
        }
    }

    vis[N] = res;
    return vis[N];
}
void printTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<string> vec;
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (root == NULL)
            vec.push_back("null");
        else
            vec.push_back(to_string(root->data));
        if (root != NULL)
        {
            q.push(root->left);
            q.push(root->right);
        }
    }
    int j = vec.size() - 1;
    while (j > 0 && vec[j] == "null")
        j--;
    vec.resize(j);
    for (int i = 0; i < j; i++)
        cout << vec[i] << ",";
    cout << vec[j];
}
int main()
{
    int n = 7;

    vector<TreeNode *> trees = allPossibleFBT(n);

    cout << "[";
    for (int i = 0; i < trees.size(); i++)
    {
        cout << "[";
        printTree(trees[i]);
        cout << "]";
        if (i != trees.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}