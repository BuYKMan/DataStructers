#ifndef CHROMOSOME_H
#define CHROMOSOME_H


#include "DoublyLinkedList.h"

class Chromosome {
private:
    DoublyLinkedList genes;

public:
    void addGene(char gene);
    char getGene(int index) const;
    void setGene(int index, char value);
    int getSize() const;
    void clear();
};

#endif
