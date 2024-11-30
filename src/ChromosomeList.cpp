/**
* Dosya Adi: ChromosomeList.cpp
* @description Chromosome'lar ile işlem yapabilmek için böyle bir sınıf oluşturdum(özel olarak crossover sonucu eklenmesi gereken yeni Chromosomelar için add fonksiyonu var)
* @course 1A
* @assignment 1.Ödev
* @date 11.11.2024
* @author B211210022 samed.deger@ogr.sakarya.edu.tr
*/
#include "../include/ChromosomeList.h"
#include <stdexcept>

ChromosomeList::ChromosomeList() : head(nullptr), tail(nullptr), size(0) {}

ChromosomeList::~ChromosomeList() {
    ChromosomeNode* current = head;
    while (current != nullptr) {
        ChromosomeNode* next = current->next;
        delete current->data; // Deletes Chromosome object
        delete current;       // Deletes node
        current = next;
    }
}

ChromosomeNode* ChromosomeList::getNode(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }

    ChromosomeNode* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

void ChromosomeList::add(Chromosome* chromosome) {
    ChromosomeNode* newNode = new ChromosomeNode(chromosome);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}


Chromosome* ChromosomeList::get(int index) const {
    return getNode(index)->data;
}

int ChromosomeList::getSize() const {
    return size;
}