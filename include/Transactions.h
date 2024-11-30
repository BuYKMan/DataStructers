#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../include/DNA.h"
#include <string>
#include <bits/stl_algo.h>
//trim fonksiyonunu kendim için yazmıştım Transactionda kullanmıştım silmek istemedim
void crossover(DNA& dna, int index1 = -1, int index2 = -1);
void mutate(DNA& dna);
//void processTransactions(DNA& dna, const std::string& filename); 
void printMenu();
void automaticOperations(DNA& dna);
inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
#endif
