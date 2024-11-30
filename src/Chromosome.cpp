/**
* Dosya Adi: Chromosome.cpp
* @description Chromosome sınıfın getter ve setter metodları oluşturdum Crossover yapabilmek için addGene fonksiyonunu burda ekledim
* @course 1A
* @assignment 1.Ödev
* @date 11.11.2024
* @author B211210022 samed.deger@ogr.sakarya.edu.tr
*/

#include "../include/Chromosome.h"


void Chromosome::clear() {
        genes.clear(); 
}
void Chromosome::addGene(char gene) {
    genes.add(gene);
}

char Chromosome::getGene(int index) const {
    return genes.get(index);
}

void Chromosome::setGene(int index, char value) {
    genes.set(index, value);
}

int Chromosome::getSize() const {
    return genes.getSize();
}





