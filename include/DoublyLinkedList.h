#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "Node.h"

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

    Node* getNode(int index) const;
    

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void clear();
    Node* getHead() const;
    Node* getTail() const;
    void add(char value);
    char get(int index) const;
    void set(int index, char value);
    int getSize() const;

    
};

#endif