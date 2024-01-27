//
// Created by Johannes Joujo on 2024-01-26.
//

#include <sstream>
#include "parser.h"



std::string parser::addOperator(std::string str, lexer Lexer) {
    std::istringstream stream(str);
    stream>>ord1;
    stream>>ord2; //plustecken
    stream>>ord2; //andra ordet
    //std::cout<<ord1<<"\n";
    //std::cout<<ord2;

    if(Lexer.lexvec==ord1){
        std::cout<<"ord1: "<<ord1<<" har hittats.\n";
    }
    if(Lexer.lexvec==ord2){
        std::cout<<"ord2: "<<ord2<<" har hittats.\n";
    }

    return ord1;
}

void parser::parsLookup(std::string str, lexer Lexer) {
    char ch=' ';

    for (int i=0;i<str.length();i++){
        if(!isalpha(str[i])&& !isspace(str[i])){
            ch=str[i];
            break;
        }
    }
    switch(ch){
        case '+':
            //std::cout<<"+++++\n";
            addOperator(str, Lexer);
            break;
            case '*':
            //std::cout<<"+++++\n";
                multiOperator(str, Lexer);
            break;
        default:
            std::cout<<"default is running now\n";
            break;
    }

}

std::string parser::multiOperator(std::string str, lexer Lexer) {
    std::istringstream stream(str);
    stream>>ord1;
    if(ord1==Lexer.lexvec) {
        std::cout << ++counter << " " << ord1 << "\n";
    }
    return ord1;
}
