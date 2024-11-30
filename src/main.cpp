/**
* Dosya Adi: main.cpp
* @description burayı çok fazla değişikliğe uğrattım en sonunda burdaki karmaşıyı çözmek için Transactions sınıfını oluşturamya karar verdim
* @course 1A
* @assignment 1.Ödev
* @date 11.11.2024
* @author B211210022 samed.deger@ogr.sakarya.edu.tr
*/


#include <iostream>
#include <fstream>
#include <string>
#include "../include/Transactions.h"

void executeMenuOption(int choice, DNA& dna) {
    int index1, index2;
    switch (choice) {
        case 1:
            crossover(dna);
            break;
        case 2:
            mutate(dna);
            break;
        case 3:
            std::cout << "Running automatic operations...\n";
            automaticOperations(dna);
            break;
        case 4:
            dna.printAllChromosomes();
            break;
        case 5:
             dna.printScreen();
            break;
        case 6:       
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
    }
}

int main() {
    DNA dna;
    std::string filename = "dna.txt";

    try {
        dna.loadFromFile(filename);
    } catch (const std::exception& e) {
        std::cerr << "Error loading DNA file: " << e.what() << std::endl;
        return 1;
    }
    int choice = 0;
    while (choice != 6) {
        printMenu(); 
        std::cin >> choice; 
        executeMenuOption(choice, dna); 
    }

    return 0;
}
