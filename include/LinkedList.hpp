#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>

template<typename T>
struct LinkedNode{
    LinkedNode(T val) : value(val), pNextNode(nullptr){}
    T value;
    LinkedNode<T>* pNextNode;
};

template<typename T>
class LinkedList{
public:
    LinkedList(T val) : pHeadNode(new LinkedNode<T>(val)){}
    ~LinkedList(){
        clear();
    }
    void push_back(const T& value){
        LinkedNode<T>* newNode = new LinkedNode<T>(value);
        if(!pHeadNode){
            pHeadNode = newNode;
        }else{
            LinkedNode<T>* curNode = pHeadNode;
            while (curNode->pNextNode){
                curNode = curNode->pNextNode;
            }
            curNode->pNextNode = newNode;
        }
    }
    void push_back(T&& value){
        LinkedNode<T>* newNode = new LinkedNode<T>(value);
        if(!pHeadNode){
            pHeadNode = newNode;
        }else{
            LinkedNode<T>* curNode = pHeadNode;
            while (curNode->pNextNode){
                curNode = curNode->pNextNode;
            }
            curNode->pNextNode = newNode;
        }
    }

    void clear(){
        if(!pHeadNode) {
            std::cout << "No element. Empty LinkedList!" << std::endl;
            return;
        }
        while (pHeadNode->pNextNode){
            LinkedNode<T> *tempNode = pHeadNode->pNextNode;
            delete pHeadNode;
            pHeadNode = tempNode;
        }
        delete pHeadNode;
        pHeadNode = nullptr;
        std::cout << "--- Cleanup Over! ---" << std::endl;
    }

    void print(){
        if(!pHeadNode) {
            std::cout << "No element. Empty LinkedList!" << std::endl;
            return;
        }
        LinkedNode<T> *curNode = pHeadNode;
        while(curNode->pNextNode){
            std::cout << curNode->value << " ";
            curNode = curNode->pNextNode;
        }
        std::cout << curNode->value << std::endl;
    }
private:
    LinkedNode<T>* pHeadNode = nullptr;
};

#endif //LINKED_LIST_HPP