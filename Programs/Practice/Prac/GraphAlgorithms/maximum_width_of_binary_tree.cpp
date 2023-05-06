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
int widthOfBinaryTree(TreeNode *root)
{

    deque<pair<TreeNode *, size_t>> queue(1, {root, 0});
    int maxTreeWidth{0};
    while (!queue.empty())
    {
        int levelWidth = queue.back().second - queue.front().second + 1;
        if (levelWidth > maxTreeWidth)
            maxTreeWidth = levelWidth;
        for (int count = queue.size(), i{0}; i < count; i++)
        {
            auto node = queue.front();
            TreeNode *qNode = node.first;
            queue.pop_front();
            if (qNode->left)
                queue.push_back({qNode->left, 2 * node.second});
            if (qNode->right)
                queue.push_back({qNode->right, 2 * node.second + 1});
        }
    }
    return maxTreeWidth;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << widthOfBinaryTree(root);

    return 0;
}