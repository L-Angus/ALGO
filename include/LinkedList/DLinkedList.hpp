#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

#include <memory>

#include "ListNode.h"

template <typename T> class DLinkedList {
public:
  DLinkedList() = default;
  ~DLinkedList() = default;

  void push_back(T val) {
    auto newNode = std::make_shared<LinkedNode<T>>(val);
    if (!mHeadNode) {
      mHeadNode = mTailNode = newNode;
      mPosition = 0;
    } else {
      auto curNode = mHeadNode;
      while (curNode != mTailNode) {
        curNode = curNode->pNextNode;
      }
      curNode->pNextNode = newNode;
      mTailNode = curNode->pNextNode;
      mPosition++;
    }
  }
  void insert(size_t position) {}
  void remove(size_t position) {}
  void pop_back() {
    if (!mHeadNode || !mTailNode)
      return;
    if (mHeadNode == mTailNode) {
      mHeadNode.reset();
      mTailNode.reset();
      return;
    }
    auto curNode = mHeadNode;
    while (curNode->pNextNode != mTailNode) {
      curNode = curNode->pNextNode;
    }
    mTailNode = curNode;
    mTailNode->pNextNode = nullptr;
  }
  void clear() {}
  void print() {
    if (!mHeadNode)
      return;
    if (mPosition == 0) {
      std::cout << mHeadNode->value << std::endl;
    } else {
      auto curNode = mHeadNode;
      while (curNode != mTailNode) {
        std::cout << curNode->value << " ";
        curNode = curNode->pNextNode;
      }
      std::cout << mTailNode->value << std::endl;
    }
  }

  bool empty() const { return (mHeadNode == nullptr); }

  void HeadNodes() { std::cout << mHeadNode.use_count() << std::endl; }
  void TailNodes() { std::cout << mTailNode.use_count() << std::endl; }

  size_t CurPosition() const { return mPosition; }
  std::shared_ptr<LinkedNode<T>> GetTailNode() const { return mTailNode; }

private:
  std::shared_ptr<LinkedNode<T>> mHeadNode = nullptr;
  std::shared_ptr<LinkedNode<T>> mTailNode = nullptr;
  size_t mPosition;
};

#endif // DOUBLE_LINKED_LIST_HPP