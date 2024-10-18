#ifndef STACK_HPP
#define STACK_HPP

#include "DLinkedList.hpp"

#include <stack>

template <typename T> class Stack {
public:
  Stack() = default;
  ~Stack() = default;

  size_t size() const { return mstack.CurPosition() + 1; }
  bool empty() const { return mstack.empty(); }
  void push(T value) { mstack.push_back(value); }
  void print() { mstack.print(); }
  T top() const { return mstack.GetTailNode()->value; }
  void pop() { mstack.pop_back(); }

private:
  DLinkedList<T> mstack;
};

#endif // STACK_HPP