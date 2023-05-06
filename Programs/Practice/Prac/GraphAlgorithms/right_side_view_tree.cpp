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

vector<int> rightSideView(TreeNode *root)
{

    vector<int> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        vector<int> x;
        while (len--)
        {
            root = q.front();
            q.pop();
            x.push_back(root->data);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        res.push_back(x[x.size() - 1]);
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> view = rightSideView(root);
    cout << "[";
    for (int i = 0; i < view.size() - 1; i++)
        cout << view[i] << ", ";
    cout << view[view.size() - 1] << "]";
    return 0;
}