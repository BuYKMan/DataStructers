#ifndef CHROMOSOMELIST_H
#define CHROMOSOMELIST_H


#include "Chromosome.h"

class ChromosomeNode {
public:
    Chromosome* data;
    ChromosomeNode* next;

    explicit ChromosomeNode(Chromosome* chrom) : data(chrom), next(nullptr) {}
};

class ChromosomeList {
private:
    ChromosomeNode* head;
    ChromosomeNode* tail; 
    int size;

    ChromosomeNode* getNode(int index) const; 

public:
    ChromosomeList();
    ~ChromosomeList();

    void add(Chromosome* chromosome);
    Chromosome* get(int index) const;
    int getSize() const;
};

#endif