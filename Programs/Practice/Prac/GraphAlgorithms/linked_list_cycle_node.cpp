#include <bits/stdc++.h>
using namespace std;

//Struture of  node
struct Node
{ 
   int data;
   Node *next;
   Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
    
// find the first cycle node
 Node *firstNode(Node *l, Node *cNode) 
 {
        while (cNode !=NULL) {
            if (l == cNode)
                return l;
            cNode = cNode->next;
            l = l->next;
        }
        return NULL;
}

// function to check if linked
 // list contains cycle or not
 Node* hasCycle(Node *head)
{
        Node *slow = head;
        Node *fast = head;

        // move slow pointer one time and
        // fast pointer 2 times
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
                // if both slow and fast are
                // at same place then return true
                // means cycle is present
                if (slow == fast)
                    return slow;
            }
        }
        // no cycle
        return NULL;
}

int main()
{
    Node *l = new Node(3);
    l->next = new Node(2);
    Node *tmp = l->next;
    l->next->next = new Node(0);
    l->next->next->next = new Node(-4);
    l->next->next->next->next = tmp;
    Node *cNode = hasCycle(l);
    if (cNode ==NULL) {
        cout<<"No cycle";
        } 
     else {
            Node *cycleNode = firstNode(l, cNode);
           cout<<cycleNode->data;
        }
    return 0;
}
