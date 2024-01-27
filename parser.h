//
// Created by Johannes Joujo on 2024-01-26.
//

#ifndef LABB1_COMPILER_DT096G_PARSER_H
#define LABB1_COMPILER_DT096G_PARSER_H

#include <iostream>
#include "lexer.h"
class parser {
public:
    int counter;
    std::string ord1;
    std::string ord2;

    std::string addOperator(std::string str, lexer Lexer);
    std::string multiOperator(std::string str, lexer Lexer);
    void parsLookup(std::string str, lexer Lexer);


};


#endif //LABB1_COMPILER_DT096G_PARSER_H
