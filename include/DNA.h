#ifndef DNA_H
#define DNA_H

#include "Chromosome.h"
#include "ChromosomeList.h"
#include <string>

class DNA {
private:
    ChromosomeList chromosomes;

public:
    ~DNA();

    void loadFromFile(const std::string& filename);
    void addChromosome(Chromosome* chromosome);
    Chromosome* getChromosome(int index) const;
    int getChromosomeCount() const;
    void printChromosome(int index) const;
    void printAllChromosomes() ;
    void printScreen();

};

#endif