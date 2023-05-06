#include <bits/stdc++.h>
using namespace std;

int main()
{

   
    std::shared_ptr<int> ptr1(new int(10));
    std::weak_ptr<int> weekPointer(ptr1);
    ptr1.reset();
    try
    {
        std::shared_ptr<int> p2(weekPointer);
    }
    catch (const std::bad_weak_ptr &e)
    {
        std::cout << "Error has occured " << e.what() << '\n';
    }

    return 0;
}
/*
class std::bad_weak_ptr

Exception possibly thrown by shared_ptr.

std::bad_weak_ptr is the type of the object thrown as exceptions by the constructors of 
std::shared_ptr that take std::weak_ptr as the argument, when the std::weak_ptr refers to 
an already deleted object.

std-bad weak ptr-inheritance.svg
Inheritance diagram


std::bad_weak_ptr::bad_weak_ptr
bad_weak_ptr() noexcept;
(1)	(since C++11)
bad_weak_ptr( const bad_weak_ptr& other ) noexcept;
(2)	(since C++11)
Constructs a new bad_weak_ptr object with an implementation-defined null-terminated byte 
string which is accessible through what().

1) Default constructor.
2) Copy constructor. If *this and other both have dynamic type std::bad_weak_ptr then 
std::strcmp(what(), other.what()) == 0.
Parameters
other	-	another exception object to copy
std::bad_weak_ptr::operator=
bad_weak_ptr& operator=( const bad_weak_ptr& other ) noexcept;
(since C++11)
Assigns the contents with those of other. If *this and other both have dynamic type 
std::bad_weak_ptr then std::strcmp(what(), other.what()) == 0 after assignment.

Parameters
other	-	another exception object to assign with
Return value
*this


File: shared_ptr_base.h
*/