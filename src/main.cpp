#include <iostream>
#include <string>

#include "HashTable/HashMap.hpp"
#include "LinkedList/Stack.hpp"
#include "Time_o1.hpp"

int main() {
  std::cout << "-- Hello Algorithm --" << std::endl;
  HashMap<int, std::string> map;
  map.put(1, "hello");
  map.put(2, "world");
  map.put(3, "hello");
  map.put(4, "world");

  map.put(5, "hello");
  map.put(6, "world");

  map.print();
  std::cout << map.Capacity() << std::endl;
  return 0;
}