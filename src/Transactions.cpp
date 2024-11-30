/**
* Dosya Adi: Transactions.cpp
* @description Genel olarak bizden istediğiniz fonksiyonları burada topladım processTransactions fonksiyonunu genel bir amaçla yazmıştım sonra silmek istemedim 
 automaticOperations() diye fonksiyon oluşturmaya karar verdim ayrıca 
 Ödev gereksinimlerinfe görmedim ama print fonksiyunun kendim için ekledim işlem yaparaken daha kolay oluyordu ve olması gerektiğini düşündüm.
* @course 1A
* @assignment 1.Ödev
* @date 25.11.2024
* @author B211210022 samed.deger@ogr.sakarya.edu.tr
*/



#include "../include/Transactions.h"
#include <iostream>
#include <fstream>
#include <sstream>

void printMenu() {
    std::cout << "\n=== DNA Operations Menu ===\n"
              << "1. Crossover\n"
              << "2. Mutation\n"
              << "3. Automatic Operations\n"
              << "4. Write to Screen\n"
              << "5. Print to Screen\n"
              << "6. Exit\n"
              << "Choose an option: ";
}

void crossover(DNA& dna, int index1, int index2) {
    if (index1 == -1 && index2 == -1) {
        std::cout << "Enter the first chromosome index: ";
        std::cin >> index1;
        std::cout << "Enter the second chromosome index: ";
        std::cin >> index2;
    }

    if (index1 < 0 || index1 >= dna.getChromosomeCount() || index2 < 0 || index2 >= dna.getChromosomeCount()) {
        std::cerr << "Invalid chromosome indices. Please ensure indices are within bounds.\n";
        return;
    }

    Chromosome* chrom1 = dna.getChromosome(index1);
    Chromosome* chrom2 = dna.getChromosome(index2);

    int middle1 = chrom1->getSize() / 2;
    int middle2 = chrom2->getSize() / 2;

    Chromosome* newChrom1 = new Chromosome();
    Chromosome* newChrom2 = new Chromosome();

    for (int i = 0; i < middle1; ++i) {
        newChrom1->addGene(chrom1->getGene(i));
    }
    for (int i = middle2; i < chrom2->getSize(); ++i) {
        newChrom1->addGene(chrom2->getGene(i));
    }

    for (int i = middle1; i < chrom1->getSize(); ++i) {
        newChrom2->addGene(chrom1->getGene(i));
    }
    for (int i = 0; i < middle2; ++i) {
        newChrom2->addGene(chrom2->getGene(i));
    }

    dna.addChromosome(newChrom1);
    dna.addChromosome(newChrom2);

    std::cout << "Crossover operation completed successfully between indices "
              << index1 << " and " << index2 << "!\n";
}

void automaticOperations(DNA& dna) {
    std::ifstream transactionFile("Islemler.txt");
    if (!transactionFile.is_open()) {
        std::cerr << "Could not open transaction.txt for automatic operations.\n";
        return;
    }
    std::string line;
  while (std::getline(transactionFile, line)) {
    char transaction;
    int index1, index2;
    int chromosomeIndex, geneIndex;

    // Satırı ayrıştır ve transaction, index1, index2 değerlerini al
    if (sscanf(line.c_str(), "%c %d %d", &transaction, &index1, &index2) == 3) {
        if (transaction == 'c') { // 'c' ile kontrol yapılmalı
            std::cout << "Automatic Crossover operation...: " << line << "\n";

            crossover(dna, index1, index2); // crossover işlemi
        } 
        else if (transaction == 'm') { // 'm' ile kontrol yapılmalı
            chromosomeIndex = index1; // İlk değer chromosomeIndex
            geneIndex = index2;       // İkinci değer geneIndex

            dna.getChromosome(chromosomeIndex)->setGene(geneIndex, 'X');
            std::cout << "Mutation: Chromosome " << chromosomeIndex
                      << ", Gene " << geneIndex << " changed to 'X'.\n";
        } 
        else {
            std::cerr << "Unknown operation: " << line << "\n";
        }
    } else {
        std::cerr << "Invalid format: " << line << "\n";
    }
}

    transactionFile.close();
}


void mutate(DNA& dna) {
    int chromosomeIndex, geneIndex;
    std::cout << "Enter the chromosome index to mutate: ";
    std::cin >> chromosomeIndex;
    std::cout << "Enter the gene index to mutate: ";
    std::cin >> geneIndex;

    try {
        dna.getChromosome(chromosomeIndex)->setGene(geneIndex, 'X');
        std::cout << "Mutation: Chromosome " << chromosomeIndex
                  << ", Gene " << geneIndex << " changed to 'X'.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error during mutation: " << e.what() << "\n";
    }
}

/*
#pragma region Printscreen

void printScreen( DNA& dna) {
    // Sonuçları saklamak için bir Chromosome nesnesi4
    Chromosome result;

    // Tüm kromozomları dolaş
    for (int i = 0; i < dna.getChromosomeCount(); ++i) {
        Chromosome* currentChromosome = dna.getChromosome(i);

        // Mevcut kromozomdan ilk karakteri al
        if (currentChromosome->getSize() == 0) {
            continue; // Boş kromozom varsa atla
        }

        char firstChar = currentChromosome->getGene(0);
        char smallestChar = firstChar;

        // ASCII karşılaştırması yap
        for (int j = 1; j < currentChromosome->getSize(); ++j) {
            char currentChar = currentChromosome->getGene(j);
            if (currentChar < smallestChar) {
                smallestChar = currentChar;
                break; // İlk küçük karakter bulundu
            }
        }

        // Sonuçlara en küçük karakteri ekle
        result.addGene(smallestChar);
    }

    // Sonuçları yazdır
    std::cout << "Sonuç: ";
    for (int i = 0; i < result.getSize(); ++i) {
        std::cout << result.getGene(i);
    }
    std::cout << std::endl;
}
#pragma endregion Printscreen
*/



/* 
void processTransactions(DNA& dna, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open transaction file: " << filename << std::endl;
        return;
    }

    std::string operation;
    while (std::getline(file, operation)) {
        std::istringstream iss(operation);
        std::string command;
        iss >> command;

        if (command == "c") {
            int index1, index2;
            iss >> index1 >> index2;
            if (iss.fail()) {
                std::cerr << "Invalid input for crossover in transaction file.\n";
                continue;
            }
            crossover(dna, index1, index2); // Use indices from file
        } else if (command == "m") {
            int chromosomeIndex, geneIndex;
            iss >> chromosomeIndex >> geneIndex;
            if (iss.fail()) {
                std::cerr << "Invalid input for mutation in transaction file.\n";
                continue;
            }
            try {
                dna.getChromosome(chromosomeIndex)->setGene(geneIndex, 'X');
                std::cout << "Mutation: Chromosome " << chromosomeIndex
                          << ", Gene " << geneIndex << " changed to 'X'.\n";
            } catch (const std::exception& e) {
                std::cerr << "Error during mutation: " << e.what() << "\n";
            }
        } else {
            std::cerr << "Unknown operation: " << command << "\n";
        }
    }

    file.close();
    std::cout << "Transaction processing completed successfully!\n";
}
*/



