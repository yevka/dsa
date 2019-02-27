#include <iostream>
#include "binary_tree.h"

int main() {
  std::cout << "hello world" << std::endl;

  binary_tree<int, int> bt;
  bt.insert(8, 8);
  bt.insert(3, 3);
  bt.insert(10, 10);
  bt.insert(1, 1);
  bt.insert(6, 6);
  bt.insert(14, 14);
  bt.insert(4, 4);
  bt.insert(7, 7);
  bt.insert(13, 13);

  bt.print_infix_travers();
  std::cout << std::endl;

  bt.print_postfix_travers();
  std::cout << std::endl;

  bt.print_prefix_travers();
  std::cout << std::endl;

  std::cout << std::endl;

  bt.erase(1);

//  bt.print_infix_travers();
//  std::cout << std::endl;

//  bt.print_postfix_travers();
//  std::cout << std::endl;

//  bt.print_prefix_travers();
//  std::cout << std::endl;


  return 0;
}
