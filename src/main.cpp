#include <iostream>

#include "LinkedList.hpp"
int main() {
  std::cout << "-- Hello Algorithm --" << std::endl;
  LinkedList<int> linkedlist(0);
  linkedlist.push_back(1);
  linkedlist.push_back(2);
  linkedlist.push_back(3);
  linkedlist.push_back(4);
  linkedlist.push_back(5);
  linkedlist.print();

  linkedlist.insert(3, 10086);
  linkedlist.print();

  // linkedlist.remove(3);
  // linkedlist.print();

  try {
    auto found = linkedlist.access(4);
    std::cout << found->value << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << " Not found such index." << '\n';
  }

  try {
    auto found = linkedlist.find(3);
    std::cout << found << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << " Not found such index." << '\n';
  }

  return 0;
}