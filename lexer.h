//
// Created by Johannes Joujo on 2024-01-21.
//

#ifndef LABB1_COMPILER_DT096G_LEXER_H
#define LABB1_COMPILER_DT096G_LEXER_H


#include <iostream>
#include <fstream>
#include <vector>
class lexer {
    int charClass;
    int lexLen;
    int token;
    char nextChar;


public:
    char lexvec[100];

    FILE *fp;
    //FILE *fp= fopen("text.txt", "r");
    void addChar();
    void getChar();
    int nextToken;
    int lookUp(char ch);
    void getNonBlank();
    int lex();

};
enum Lexer{
    add=1,
    multi,
    lpar,
    hpar,
    punkt,
    lbrace,
    hbrace,
    LETTER,
    UNKNOWN,
    DIGIT,
    IDENT,
    INT_LIT
};

#endif //LABB1_COMPILER_DT096G_LEXER_H
