#include <iostream>
#include <limits>

void foo(short){
   std::cout<<"short Ÿ��";
}

void foo(int) {
   std::cout<<"int Ÿ��";
}

void foo(long) {
   std::cout<<"long Ÿ��";
}

int main()
{
   
   short a=5;
   foo(1);
   foo(a);
   foo(1L);
   return 0;
}