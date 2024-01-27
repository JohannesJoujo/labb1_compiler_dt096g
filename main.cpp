#include <iostream>
#include "lexer.h"
#include "parser.h"

int main() {
    lexer Lexer;
    parser Parser;
    /* Open the input data file and process its contents */

    std::string mystr="johannes * joujo";


    //FILE *in_fp;
    Lexer.fp = fopen("text.txt", "r");
    if (Lexer.fp == nullptr)
        std::cout<<"ERROR - cannot open text.txt \n";
    else {
        Lexer.getChar();
        do {
            Lexer.lex();
            Parser.parsLookup(mystr, Lexer);

        } while (Lexer.nextToken != EOF);
    }

    return 0;


}
