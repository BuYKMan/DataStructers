/**
* Dosya Adi: DNA.cpp
* @description Genel olarak dna.txt dosyasını okuyup Chromosome ve ChromoseList sınıfınıda kullanarak bağlı listeyi oluşturması için bu classı oluşturdum.
* @course 1A
* @assignment 1.Ödev
* @date 11.11.2024
* @author B211210022 samed.deger@ogr.sakarya.edu.tr
*/

#include "../include/DNA.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

DNA::~DNA() = default;

void DNA::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open DNA file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        Chromosome* chromosome = new Chromosome();
        for (char gene : line) {
            if (!std::isspace(gene)) {
                chromosome->addGene(gene);
            }
        }
        chromosomes.add(chromosome);
    }
    file.close();
}

void DNA::addChromosome(Chromosome* chromosome) {
    chromosomes.add(chromosome);
}

Chromosome* DNA::getChromosome(int index) const {
    return chromosomes.get(index);
}

int DNA::getChromosomeCount() const {
    return chromosomes.getSize();
}

void DNA::printChromosome(int index) const {
    if (index < 0 || index >= getChromosomeCount()) {
        throw std::out_of_range("Invalid chromosome index");
    }

    Chromosome* chrom = getChromosome(index);
    std::cout << "Chromosome " << index << ": ";
    for (int i = 0; i < chrom->getSize(); ++i) {
        
        std::cout << chrom->getGene(i) << " ";
    }
    std::cout << std::endl;
}

void DNA::printAllChromosomes()  {
    std::cout << "=== Current DNA State ===" << std::endl;
    for (int i = 0; i < getChromosomeCount(); ++i) {
        printChromosome(i);
    }
    std::cout << "=========================" << std::endl;
}

void DNA::printScreen() {
    std::ifstream file("Dna.txt");
    if (!file.is_open()) {
        std::cerr << "Dosya açılamadı!" << std::endl;
        return;
    }

    std::string line;
    DoublyLinkedList result;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::istringstream iss(line);
        std::string segment;
        DoublyLinkedList tempL;

        // Harf ve rakamları bağlı listeye ekle
        while (iss >> segment) {
            if (segment.size() == 1 && std::isalnum(segment[0])) {
                tempL.add(segment[0]);
            }
        }

        if (!tempL.getHead()) {
            continue;
        }

        // İlk elemanı al
        Node* current = tempL.getTail();  // Bağlı listenin son düğümünden başla
        char firstChar = tempL.getHead()->data;  // İlk elemanı sakla
        char smallestChar = firstChar;

        // Sondan başa doğru ASCII karşılaştırması yap
        while (current) {
            if (current->data < smallestChar) {
                smallestChar = current->data;
                break;  // İlk küçük karakter bulundu
            }
            current = current->prev;  // Geriye git
        }

        // En küçük karakteri sonuç listesine ekle
        result.add(smallestChar);

        // Geçici listeyi temizle
        tempL.clear();
    }

    file.close();

    // Sonuçları ekrana yazdır
    std::cout << "Sonuç: ";
    Node* current = result.getHead();
    while (current) {
        std::cout << current->data;
        current = current->next;
    }
    std::cout << std::endl;

    // Sonuç listesini temizle
    result.clear();
}
