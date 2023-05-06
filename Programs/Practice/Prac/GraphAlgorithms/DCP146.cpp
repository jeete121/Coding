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
TreeNode *pruneTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && root->data == 0)
        return NULL;
    else
        return root;
}

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root->right->left->left = new TreeNode(0);
    root->right->left->right = new TreeNode(0);

    TreeNode *res = pruneTree(root);
    cout << "[";
    printTree(res);
    cout << "]";
    return 0;
}