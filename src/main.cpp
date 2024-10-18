#include <iostream>

#include "LinkedList/Stack.hpp"
#include "Time_o1.hpp"

int main() {
  std::cout << "-- Hello Algorithm --" << std::endl;
  Stack<double> mStack;
  std::cout << "Empty = " << mStack.empty() << std::endl;
  mStack.push(10086);
  // mStack.push(2006);
  // mStack.push(0);
  mStack.print();
  std::cout << "Empty = " << mStack.empty() << std::endl;
  std::cout << "Size = " << mStack.size() << std::endl;
  auto Top = mStack.top();
  std::cout << "Top = " << Top << std::endl;
  mStack.pop();
  std::cout << "Empty = " << mStack.empty() << std::endl;
  mStack.print();
  return 0;
}