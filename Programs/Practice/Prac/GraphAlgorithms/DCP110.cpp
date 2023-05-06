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
vector<vector<int>> res;
void dfs(TreeNode *root, vector<int> path)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    //If the node is leaf node
    if (root->left == NULL && root->right == NULL)
        res.push_back(path);
    //If the node is not a leaf node
    else
    {
        //call for left subtree
        dfs(root->left, path);

        //call for right subtree
        dfs(root->right, path);
    }
}
vector<string> binaryTreePaths(TreeNode *root)
{
    res.clear();
    vector<int> path;
    vector<string> ans;
    dfs(root, path);
    for (int i = 0; i < res.size(); i++)
    {
        string str = "";
        for (int j = 0; j < res[i].size(); j++)
        {
            str += to_string(res[i][j]);
            if (j != res[i].size() - 1)
                str += ",";
        }
        ans.push_back(str);
    }
    return ans;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    vector<string> paths = binaryTreePaths(root);
    cout << "[";
    for (int i = 0; i < paths.size() - 1; i++)
    {
        cout << "[";
        cout << paths[i] << ",";
        cout << "],";
    }
    cout << "[";
    cout << paths[paths.size() - 1];
    cout << "]";
    cout << "]";
    return 0;
}