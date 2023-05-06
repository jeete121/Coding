#include <bits/stdc++.h>
using namespace std;
struct ListNode
{ 
   int val;
   ListNode *next;
   ListNode(int data)
    {
        this->val=data;
        this->next=NULL;
    }
};
void linkedListTraversal(ListNode *node)
{
        while (node != NULL) {
            cout<<node->val<<" ";
            node = node->next;
        }
}

//function to find length of linked list
int linkedListLength(ListNode *node)
{
        int length = 0;
        // iterate untill end of list
        while (node !=NULL) {
            node = node->next;
            length++;
        }
        return length;
}
//function to check intersection point
//of two linked list
ListNode* getIntersectionNode(ListNode* headA,ListNode *headB) 
{
    if (headA==NULL || headB==NULL) {
            return NULL;
        }
        // find length of both list
        int lenA = linkedListLength(headA);
        int lenB = linkedListLength(headB);

        // if first is greater then second
        // then skip
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff > 0) {
                diff--;
                headA = headA->next;
            }
            // if second is greater then second
            // then skip
        } else if (lenA < lenB) {
            int diff = lenB - lenA;
            while (diff > 0) {
                diff--;
                headB = headB->next;
            }
        }
        // find intersection in both list
        while (headA !=NULL) {
            // if intersection found the return
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
}
int main()
{
        // create two list
        ListNode *l1, *l2;
        // first list add two node which is different
        l1 = new ListNode(4);
        l1->next = new ListNode(1);

        // second list add three node which is different
        l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(1);

        // for intersection create command node
        // and assign to both list
        ListNode *n8 = new ListNode(8);
        l1->next->next = n8;
        l2->next->next->next = n8;

        ListNode *n4 = new ListNode(4);
        l1->next->next->next = n4;
        l2->next->next->next->next = n4;

        ListNode *n5 = new ListNode(5);
        l1->next->next->next->next = n5;
        l2->next->next->next->next->next = n5;

        ListNode *isectionNode = getIntersectionNode(l1, l2);
        cout<<"Intersected at "<<isectionNode->val;

 return 0;
}