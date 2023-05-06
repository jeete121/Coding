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
void dfs(TreeNode *node, vector<int> &res)
{
    if (!node)
        return;
    dfs(node->left, res);
    res.push_back(node->data);
    dfs(node->right, res);
}
TreeNode *construct(vector<int> &res, int start, int end)
{
    if (start < 0 || end >= res.size() || start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    TreeNode *root2 = new TreeNode(res[mid]);
    root2->left = construct(res, start, mid - 1);
    root2->right = construct(res, mid + 1, end);
    return root2;
}
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> res;
    dfs(root, res);

    return construct(res, 0, res.size() - 1);
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
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    TreeNode *res = balanceBST(root);

    cout << "[";
    printTree(res);
    cout << "]";
    return 0;
}