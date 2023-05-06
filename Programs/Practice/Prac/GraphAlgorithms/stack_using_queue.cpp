#include <bits/stdc++.h>
using namespace std;
class StackQueue
{
    public:
    queue<int> q1, q2;

     StackQueue() {
        
     }

    int size() {
        return q1.size();
    }

    // Remove the top item from the stack
    int pop() {
        if (q1.empty()) {
            cout<<"Underflow!!";
            return -1;
        }
        else
         {
             int temp=q1.front();
             q1.pop();
             return temp;
         }
    }

    int top() {
        if (q1.empty()) {
            cout<<"Underflow!!";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    // insert item on to the stack
    void push(int val) 
    {
        // move all the item from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        // move all the item back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
   }
};
int main()
{

        // create stack with size
        StackQueue s;
        // add 1 element
        s.push(1);
        cout<<"isEmpty(): "<<s.isEmpty(); 
        cout<<": Top() : "<<s.top()<<": Size() : "<<s.size()<<"\n";
        // pop element
        s.push(2);
        cout<<"isEmpty(): "<<s.isEmpty();
        cout<<": Pop() : "<<s.pop();
        cout<<": Size() : "<<s.size()<<"\n";
        // pop element
        cout<<"Top(): "<<s.top();
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": Pop() : "<<s.pop();
        cout<<": Size() : "<<s.size()<<"\n";
        return 0;
}


