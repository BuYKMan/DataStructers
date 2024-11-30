/**
* Dosya Adi: LinkedList.cpp
* @description tail kullandım işlem kolaylığı olması için 
* @course 1A
* @assignment 1.Ödev
* @date 11.11.2024
* @author B211210022 samed.deger@ogr.sakarya.edu.tr
*/
#include "../include/DoublyLinkedList.h"
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
   Node* DoublyLinkedList::getTail() const {
        return tail;
    }
Node* DoublyLinkedList::getNode(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}
  void DoublyLinkedList::clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr; // Listeyi temizle
    }
  void DoublyLinkedList::add(char value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
  }
char DoublyLinkedList::get(int index) const {
    return getNode(index)->data;
}

void DoublyLinkedList::set(int index, char value) {
    getNode(index)->data = value;
}

int DoublyLinkedList::getSize() const {
    return size;
}
Node* DoublyLinkedList::getHead() const {
        return head;
    }