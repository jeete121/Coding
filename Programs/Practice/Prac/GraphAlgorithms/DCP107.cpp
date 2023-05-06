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
//Function to find the level order
//traversal of the tree
vector<int> levelOrderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    //Run loop till queue is not empty
    while (!q.empty())
    {
        int len = q.size();
        vector<int> vec;
        while (len--)
        {
            root = q.front();
            q.pop();
            res.push_back(root->data);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
    return res;
}
int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->right->left = new TreeNode(4);
    tree->right->right = new TreeNode(5);

    vector<int> res = levelOrderTraversal(tree);
    int n = res.size();
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";
    return 0;
}
//Time Complexity: O(n)
