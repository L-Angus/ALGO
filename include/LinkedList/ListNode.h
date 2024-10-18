#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

template <typename T> struct LinkedNode {
  LinkedNode(T val) : value(val), pNextNode(nullptr) {}
  T value;
  std::shared_ptr<LinkedNode<T>> pNextNode;
};

#endif // LIST_NODE_HPP