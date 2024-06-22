#include <iostream>
#include <vector>

class A {
public:

    ~A() {
        std::cout << "A ¼Ò¸êÀÚ"<<'\n';
    }
};

class B : public A {
public:

    ~B() {
        std::cout << "B ¼Ò¸êÀÚ"<<'\n';
    }
};

int main()
{
    A* p{new B};
    delete p;

    return 0;
}