#include <iostream>
#include "binary_tree.h"

//static
//void change(int*& a, int &b) {
//  a = &b;
//}

static
void change(int* a, int &b) {
  *a = b;
}



int main() {
  std::cout << "hello world" << std::endl;

  int a = 2;
  int b = 1;
  int* pa = &a;

  std::cout << "a = " << a << " b = " << b << " pa = " << *pa << "\n";
  change(pa, b);
  std::cout << "a = " << a << " b = " << b << " pa = " << *pa << "\n";

  return 0;
}
