#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include "ListNode.h"
#include <memory>

template <typename T> class CLinkedList {
public:
  CLinkedList() = default;
  ~CLinkedList() = default;

  void push_back(T val) {}
  void insert(size_t position) {}
  void remove(size_t position) {}
  void clear() {}
  void print() {}

private:
  std::unique_ptr<LinkedNode<T>> mHeadNode = nullptr;
  std::unique_ptr<LinkedNode<T>> mTailNode = nullptr;
};

#endif // CIRCULAR_LINKED_LIST_HPP