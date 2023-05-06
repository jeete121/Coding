#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *addOneRow(TreeNode *root, int v, int d, bool isLeft = true)
{
    if (d == 1)
    {
        TreeNode *left = isLeft ? root : NULL, *right = isLeft ? NULL : root;
        return new TreeNode(v, left, right);
    }

    if (root != NULL)
    {
        root->left = addOneRow(root->left, v, d - 1);
        root->right = addOneRow(root->right, v, d - 1, false);
    }

    return root;
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
            vec.push_back(to_string(root->val));
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
    cout << "[";
    for (int i = 0; i < j; i++)
        cout << vec[i] << ",";
    cout << vec[j];
    cout << "]";
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);

    int v = 1, d = 2;
    TreeNode *newroot = addOneRow(root, v, d);

    printTree(newroot);

    return 0;
}