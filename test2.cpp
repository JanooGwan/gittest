#include <iostream>
#include <vector>

class A {
public:

    ~A() {
        std::cout << "A �Ҹ���"<<'\n';
    }
};

class B : public A {
public:

    ~B() {
        std::cout << "B �Ҹ���"<<'\n';
    }
};

int main()
{
    A* p{new B};
    delete p;

    return 0;
}