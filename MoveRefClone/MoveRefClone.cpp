// MoveRefClone.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class A
{
public:
    int* i = nullptr;

    A()
    {
        i = new int(1);
    }

    A(const A& rhs)
    {
        i = new int(*rhs.i);
    }

    A(A&& rhs)
    {
        i = rhs.i;
        rhs.i = nullptr;
    }

    A& operator=(const A& rhs)
    {
        i = new int(*rhs.i);
        return *this;
    }

    A& operator=(A&& rhs)
    {
        i = rhs.i;
        rhs.i = nullptr;
        return *this;
    }




};


int main()
{
    A a;
    A a2;

    a2 = a;

    std::cout << a.i << '\n';
    std::cout << a2.i << '\n';

    std::cout << *a.i << '\n';
    std::cout << *a2.i << '\n';

    *a2.i = 2;

    std::cout << *a.i << '\n';
    std::cout << *a2.i << '\n';

}

