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

//function to find the average of all
//levels
vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int len = q.size();
        int n = len;
        long long int sum = 0;
        while (len--)
        {
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        double x = (double)sum / n;
        res.push_back(x);
    }
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<double> ave = averageOfLevels(root);
    cout << "[";
    for (int i = 0; i < ave.size() - 1; i++)
        cout << ave[i] << ", ";

    cout << ave[ave.size() - 1] << "]";
    return 0;
}