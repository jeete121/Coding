#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
    public:
    stack<int> s1, s2;

     QueueStack() {
    }

    // add value in queue
    void enQueue(int val) {
        // move all the item from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        // move all back item from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

// get front and front remove element from queue
    int  deQueue() {
        if (s1.empty()) {
            cout<<"Underflow!!";
            return -1;
        }
        int temp=s1.top();
        s1.pop();
        return temp;

    }

    // only get front element from queue
     int front() {
        if (s1.empty()) {
            cout<<"Underflow!!";
            return -1;
        }
        return s1.top();
    }

     int size() {
        return s1.size();
    }

    bool isEmpty() {
        return s1.empty();
    }

};
int main()
{
    QueueStack  s ;

        // push 1 element
        cout<<"enQueue(1): ";
        s.enQueue(1); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<< ": Size() : " + s.size()<<endl;
        // pop element
        cout<<"front(): " + s.front(); 
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": deQueue() : "<<s.deQueue();
        cout<<": Size() : " + s.size()<<endl;
        // pop element
        cout<<"front(): "<<s.front();
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": deQueue() : "<<s.deQueue();
        cout<<": Size() : " + s.size()<<endl;
        // push another element
        cout<<"enQueue(1): ";
        s.enQueue(1);
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : " + s.size()<<endl;
        // push another element
        cout<<"enQueue(2): ";
        s.enQueue(2);
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : "<<s.size()<<endl;
        // push another element
        cout<<"enQueue(3): ";
        s.enQueue(3);
        cout<<": isEmpty(): " <<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : "<<s.size()<<endl;
        // push another element
        cout<<"enQueue(4): ";
        s.enQueue(4);
        cout<<": isEmpty(): "<<s.isEmpty();
        cout<<": front() : "<<s.front();
        cout<<": Size() : "<<s.size()<<endl;
        return 0;
}



