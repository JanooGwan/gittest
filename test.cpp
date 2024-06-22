#include <iostream>
#include <limits>

void foo(short){
   std::cout<<"short 타입";
}

void foo(int) {
   std::cout<<"int 타입";
}

void foo(long) {
   std::cout<<"long 타입";
}

int main()
{
   
   short a=5;
   foo(1);
   foo(a);
   foo(1L);
   return 0;
}