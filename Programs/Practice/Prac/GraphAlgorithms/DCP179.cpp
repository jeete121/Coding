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
int findLastSmaller(vector<int> &nodes,
                    int first, int last, int cut)
{

    if (last < first || nodes[first] > cut)
        return first - 1;

    int low = first, high = last, mid;

    while (low < high && nodes[high] > cut)
    {

        mid = low + (high - low + 1) / 2;

        if (nodes[mid] > cut)
        {

            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }

    return high;
}
TreeNode *recursiveFromPostOrder(vector<int> &nodes,
                                 int leftIndex, int rightIndex)
{

    if (rightIndex < leftIndex)
        return NULL;

    if (rightIndex == leftIndex)
        return new TreeNode(nodes[leftIndex]);

    int rootval = nodes[rightIndex];

    TreeNode *root = new TreeNode(rootval);

    int leftLast = findLastSmaller(nodes,
                                   leftIndex,
                                   rightIndex - 1, rootval);

    root->left = recursiveFromPostOrder(nodes, leftIndex,
                                        leftLast);

    root->right = recursiveFromPostOrder(nodes, leftLast + 1,
                                         rightIndex - 1);
    return root;
}
TreeNode *fromPostOrder(vector<int> &nodes)
{

    if (nodes.size() == 0)
        return NULL;
    return recursiveFromPostOrder(nodes, 0, nodes.size() - 1);
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
    cout << "[";
    for (int i = 0; i < j; i++)
        cout << vec[i] << ",";
    cout << vec[j];
    cout << "]";
}
int main()
{
    vector<int> postorder = {2, 4, 3, 8, 7, 5};

    TreeNode *root = fromPostOrder(postorder);

    printTree(root);

    return 0;
}
