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
vector<int> v;
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    //call for left subtree
    inorder(root->left);

    //data
    v.push_back(root->data);

    //right subtree
    inorder(root->right);
}
vector<int> findTarget(TreeNode *root, int k)
{
    inorder(root);
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == k)
        {
            return {v[i], v[j]};
        }
        else if (v[i] + v[j] > k)
            j--;
        else
            i++;
    }
    return {};
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(15);
    int k = 20;
    vector<int> res = findTarget(root, k);

    if (res.size() != 0)
    {
        cout << res[0] << " " << res[1] << "\n";
    }
    else
    {
        cout << "No pair with given sum\n";
    }
    return 0;
}