#include <iostream>

#include "LinkedList.hpp"
int main(){
    std::cout << "-- Hello Algorithm --" << std::endl;
    LinkedList<int> linkedlist(0);
    linkedlist.push_back(1);
    linkedlist.push_back(2);
    linkedlist.push_back(3);
    linkedlist.push_back(4);
    linkedlist.push_back(5);
    linkedlist.print();

    // linkedlist.clear();
    // linkedlist.print();

    // linkedlist.print();
    return 0;
}