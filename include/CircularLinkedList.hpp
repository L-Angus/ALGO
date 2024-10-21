#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <memory>

template<typename T>
struct ListNode{
    T value;
    std::shared_ptr<ListNode<T>> next;
    ListNode(T val) : value(val), next(nullptr){}
};


template<typename T>
class CircularLinkedList{
public:
    CircularLinkedList(){}
    ~CircularLinkedList(){} 

    void push_back(T value){
        auto newNode = std::make_shared<ListNode<T>>(value);
        if(!mhead){
            mhead = newNode;
            mtail = newNode;
            mtail->next = mhead;
        }else{
            mtail->next = newNode;
            mtail = newNode;
            newNode->next = mhead;
        }
        mCount++;
    }

    // void clear(){}

    void print(){
        if(mCount == 0) return;
        std::shared_ptr<ListNode<T>> curNode = mhead;
        do{
            std::cout << curNode->value << " ";
            curNode = curNode->next;
        }while(curNode->next != mhead);
        std::cout << curNode->value << std::endl;
    }

private:
    std::shared_ptr<ListNode<T>> mhead = nullptr;
    std::shared_ptr<ListNode<T>> mtail = nullptr;
    size_t mCount = 0;
};

#endif //CIRCULAR_LINKED_LIST_HPP