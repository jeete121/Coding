#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left,*right;
    Node(int key)
    {
        this->key=key;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void spiralOrderTraversal(Node* root)
{
    if (root == nullptr)
        return;

    // create an empty double ended queue and enqueue root node
    list<Node*> deque;     // or use deque
    deque.push_front(root);

    // flag used to differentiate between odd or even level
    bool flag = false;

    // run till deque is not empty
    while (!deque.empty())
    {
        // calculate number of nodes in current level
        int nodeCount = deque.size();

        // print left to right
        if (flag)
        {
           // process each node of current level and enqueue their
           // non-empty left and right child to deque
           while (nodeCount)
           {
                // pop from front if flag is true
                Node* curr = deque.front();
                deque.pop_front();

                cout << curr->key << " ";

                // push left child to end followed by right child if flag is true

                if (curr->left != nullptr)
                    deque.push_back(curr->left);

                if (curr->right != nullptr)
                    deque.push_back(curr->right);

                nodeCount--;
           }
        }

        // print right to left
        else
        {
           // process each node of current level and enqueue their
           // non-empty right and left child to queue
           while (nodeCount)
           {
                // Important - pop from back if flag is false
                Node* curr = deque.back();
                deque.pop_back();

                cout << curr->key << " ";   // print front node

                // Important - push right child to front followed by left
                // child if flag is false

                if (curr->right != nullptr)
                    deque.push_front(curr->right);

                if (curr->left != nullptr)
                    deque.push_front(curr->left);

                nodeCount--;
           }
        }

        // flip the flag for next level
        flag = !flag;
        cout << endl;
    }
}

/*
void SpiralOrderTraversal(Node *root)
{
  if(root==nullptr)
     return;
  list<Node*> deque;
  deque.push_front(root);
  bool flag=false;
  while(!deque.empty())
    {
        int n=deque.size();
        if(flag)
         {
             while(n)
              {
                  Node *curr=deque.front();
                  deque.pop_front();
                  cout<<curr->key<<" ";
                  if(curr->left)
                    deque.push_back(curr->left);
                  if(curr->right)
                     deque.push_back(curr->right);
                n--;
              }
         }
         else
         {
            while(n)
             {
                 Node *curr=deque.front();
                 deque.pop_front();
                 cout<<curr->key<<" ";
                 if(curr->right)
                   deque.push_front(curr->right);
                  if(curr->left)
                    deque.push_front(curr->left);
                n--;
             }
         }
         flag=!flag;
         cout<<endl;
    }
}*/
int main()
{
    Node* root = nullptr;
    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    SpiralOrderTraversal(root);
    return 0;
}