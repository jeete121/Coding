#include <bits/stdc++.h>
using namespace std;

//structure of the node
struct Node 
{
    int val;
    vector<Node*> children;

     Node() {
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 //function for pre-order traversal
vector<int> preOrder(Node* root) 
{
        vector<int> res;
        if(root==NULL)
              return res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
        Node *curr=st.top();
               st.pop();
            res.push_back(curr->val);
            for(auto it=curr->children.rbegin();it!=curr->children.rend();it++)
                  st.push(*it);     
         
        }
        return res;
}

int main()
{
        // 3 node child
        vector<Node*> node3Child;
        node3Child.push_back(new Node(5));
        node3Child.push_back(new Node(6));

        // 1 node child
        vector<Node*> node1Child;
        node1Child.push_back(new Node(3, node3Child));
        node1Child.push_back(new Node(2));
        node1Child.push_back(new Node(4));

        // root node
        Node *node = new Node(1, node1Child);

        vector<int> result=preOrder(node);
       for(int i=0;i<result.size();i++)
          cout<<result[i]<<" ";
       return 0;
        
}
