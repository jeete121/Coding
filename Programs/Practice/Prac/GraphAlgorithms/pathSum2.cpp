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
void pathSum(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &result)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        if (targetSum == 0)
            result.push_back(path);
        return;
    }
    if (root->left)
    {
        path.push_back(root->left->data);
        pathSum(root->left, targetSum - root->left->data, path, result);
        path.pop_back();
    }
    if (root->right)
    {
        path.push_back(root->right->data);
        pathSum(root->right, targetSum - root->right->data, path, result);
        path.pop_back();
    }
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> result;
    vector<int> path(1, root->data);
    pathSum(root, targetSum - root->data, path, result);
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    vector<vector<int>> paths = pathSum(root, targetSum);

    cout << "[";
    for (int i = 0; i < paths.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j];
            if (j != paths[i].size() - 1)
                cout
                    << ", ";
        }
        cout << "]";
        if (i != paths.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}