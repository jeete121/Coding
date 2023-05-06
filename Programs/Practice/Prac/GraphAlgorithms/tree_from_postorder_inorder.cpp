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

TreeNode *buildTree(vector<int> &inorder, int instart, int inend,
                    vector<int> &postorder, int poststart, int postend)
{
    if (poststart > postend)
        return NULL;
    TreeNode *root = new TreeNode(postorder[postend]);
    int k = 0;
    for (int i = instart; i <= inend; i++)
    {
        if (inorder[i] == postorder[postend])
        {
            k = i;
            break;
        }
    }
    root->left = buildTree(inorder, instart, k - 1, postorder,
                           poststart, poststart + k - 1 - instart);
    root->right = buildTree(inorder, k + 1, inend, postorder,
                            postend - inend + k, postend - 1);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(inorder, postorder);
    printTree(root);
    return 0;
}
