//
// Created by Johannes Joujo on 2024-01-21.
//

#include "lexer.h"
#include <iostream>
#include "plus.h"


int lexer::lookUp(char ch) {
    lexer lexer;
    switch (ch) {
        case '+':
            addChar();
            nextToken = add;
            //plus(str, i);
            break;
        case '*':
            std::cout << "multi() \n";
            addChar();
            nextToken = multi;
            break;
        case '(':
            std::cout << "lpar() \n";
            addChar();
            nextToken = lpar;
            break;
        case ')':
            std::cout << "hpar() \n";
            addChar();
            nextToken = hpar;
            break;
        case '.':
            //std::cout << "punkt() \n";
            addChar();
            nextToken = punkt;
            break;
        case '{':
            //std::cout << "lbrace() \n";
            addChar();
            nextToken = lbrace;
            break;
        case '}':
            std::cout << "hbrace() \n";
            addChar();
            nextToken = hbrace;
            break;
        default:
            addChar();
            nextToken = EOF;
            break;
    }
    return nextToken;
}

void lexer::addChar() {
    if(lexLen<=100) {
        lexvec[lexLen++] = nextChar;
        lexvec[lexLen] = 0;
    }else{
        std::cout<<"Too long expression\n";
    }
}

void lexer::getChar() {
    if ((nextChar = std::getc(fp))) {
        if (isalpha(nextChar)) {
            charClass = LETTER;
        } else if (isalnum(nextChar)) {
            charClass = DIGIT;
        } else {
            charClass = UNKNOWN;
        }
    } else {
        charClass = EOF;//pga EOF
    }

}

void lexer::getNonBlank() {
    while (isspace(nextChar)) {
        getChar();
    }
}

int lexer::lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
        nextToken=IDENT;
        break;
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken=INT_LIT;
            break;
        case UNKNOWN:
            lookUp(nextChar);
            getChar();
            break;
        case EOF:
            nextToken=EOF;
            lexvec[0]='E';
            lexvec[1]='O';
            lexvec[2]='F';
            lexvec[3]=0;
            break;

    }
    //std::cout<<"the next token is: "<<nextToken<< " the next lex is: "<<lexvec<<"\n";
    //std::cout<<lexvec;
    return nextToken;
}


