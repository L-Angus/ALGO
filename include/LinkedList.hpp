#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>

template <typename T> struct LinkedNode {
  LinkedNode(T val) : value(val), pNextNode(nullptr) {}
  T value;
  LinkedNode<T> *pNextNode;
};

template <typename T> class LinkedList {
public:
  LinkedList(T val) : pHeadNode(new LinkedNode<T>(val)) {}
  ~LinkedList() { clear(); }
  void push_back(const T &value) {
    LinkedNode<T> *newNode = new LinkedNode<T>(value);
    if (!pHeadNode) {
      pHeadNode = newNode;
    } else {
      LinkedNode<T> *curNode = pHeadNode;
      while (curNode->pNextNode) {
        curNode = curNode->pNextNode;
      }
      curNode->pNextNode = newNode;
    }
    m_position++;
  }

  void insert(size_t position, T value) {
    if (position > m_position) {
      throw std::runtime_error("Position out of range.");
    }
    LinkedNode<T> *newNode = new LinkedNode<T>(value);
    if (position == 0) {
      newNode->pNextNode = pHeadNode;
      pHeadNode = newNode;
    } else {
      LinkedNode<T> *curNode = pHeadNode;
      for (size_t curPosition = 0; curPosition < position - 1; ++curPosition) {
        curNode = curNode->pNextNode;
      }
      newNode->pNextNode = curNode->pNextNode;
      curNode->pNextNode = newNode;
    }
  }

  void remove(size_t position) {
    if (position > m_position) {
      throw std::runtime_error("Position out of range.");
    }
    LinkedNode<T> *toDelete = nullptr;
    if (position == 0) {
      toDelete = pHeadNode;
      pHeadNode = pHeadNode->pNextNode;
    } else {
      LinkedNode<T> *curNode = pHeadNode;
      size_t prev = position - 1;
      for (size_t curPosition = 0; curPosition < prev; ++curPosition) {
        curNode = curNode->pNextNode;
      }
      toDelete = curNode->pNextNode;
      curNode->pNextNode = toDelete->pNextNode;
      toDelete->pNextNode = nullptr;
    }
    delete toDelete;
    m_position--;
  }

  LinkedNode<T> *access(size_t position) {
    if (position > m_position) {
      throw std::runtime_error("Position out of range.");
    }
    if (position == 0) {
      return pHeadNode;
    }
    LinkedNode<T> *curNode = pHeadNode;
    for (size_t curPos = 0; curPos < position - 1; ++curPos) {
      curNode = curNode->pNextNode;
    }
    return curNode->pNextNode;
  }

  T find(size_t position) {
    if (position > m_position) {
      throw std::runtime_error("Position out of range.");
    }
    if (position == 0) {
      return pHeadNode->value;
    }
    LinkedNode<T> *curNode = pHeadNode;
    for (size_t curPos = 0; curPos < position - 1; ++curPos) {
      curNode = curNode->pNextNode;
    }
    return curNode->pNextNode->value;
  }

  void clear() {
    if (!pHeadNode) {
      std::cout << "No element. Empty LinkedList!" << std::endl;
      return;
    }
    while (pHeadNode->pNextNode) {
      LinkedNode<T> *tempNode = pHeadNode->pNextNode;
      delete pHeadNode;
      pHeadNode = tempNode;
    }
    delete pHeadNode;
    pHeadNode = nullptr;
    std::cout << "--- Cleanup Over! ---" << std::endl;
  }

  void print() {
    if (!pHeadNode) {
      std::cout << "No element. Empty LinkedList!" << std::endl;
      return;
    }
    LinkedNode<T> *curNode = pHeadNode;
    while (curNode->pNextNode) {
      std::cout << curNode->value << " ";
      curNode = curNode->pNextNode;
    }
    std::cout << curNode->value << std::endl;
  }

private:
  LinkedNode<T> *pHeadNode = nullptr;
  size_t m_position = 0;
};

#endif // LINKED_LIST_HPP