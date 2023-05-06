#include <bits/stdc++.h>
using namespace std;

class MyIterator
{
private:
    MyIterator *nextIt = NULL;
    int data;

public:
    MyIterator(MyIterator *nextPtr = NULL)
    {
        nextIt = nextPtr;
    }

    //function to get the data
    int getData()
    {
        return data;
    }

   //funtion to set the data
    void setData(int newData)
    {
        data = newData;
    }
    
    //function to set the next iterator
    void setNextIt(MyIterator *nxt)
    {
        nextIt = nxt;
    }

    //function to check for next terator
    bool hasNext()
    {
        return nextIt != NULL;
    }

    //function to get the next value
    int next()
    {
        return nextIt->getData();
    }
};

struct NoNextException : public exception
{

    const char *what() const throw()
    {
        return "Not Exist";
    }
};

class PeekableInterface : public MyIterator
{
public:
    PeekableInterface(PeekableInterface *nextPtr = NULL)
    {
        this->setNextIt(nextPtr);
    }
    int peek()
    {
        try
        {
            if (this->hasNext())
                return this->next();
            else
                throw NoNextException();
        }
        catch (NoNextException &e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }
};

int main()
{

    PeekableInterface *it = new PeekableInterface();
    it->setData(1);
    PeekableInterface *it2 = new PeekableInterface(it);
    it2->setData(2);
    PeekableInterface *it3 = new PeekableInterface(it2);
    it3->setData(3);
    cout << it3->peek() <<"\n";
    cout << it3->next() <<"\n";
    cout << it2->peek() <<"\n";
    cout << it->peek() <<"\n";
    return 0;
}
