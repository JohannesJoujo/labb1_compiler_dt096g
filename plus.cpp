//
// Created by Johannes Joujo on 2024-01-20.
//
#include "plus.h";

int plus(std::string &str, size_t pointer){
    std::cout<<str<<"\n";
    std::cout<<str[pointer]<<"\n";
    std::string ord1="";
    std::string ord2="";
    int counter=pointer;
    int count=0;

    while(counter>0 && str[counter]!='"'){
        counter--;
        count++;
    }
    for(int i=0;i<count;i++){
        ord1.push_back(str[i]);
    }

    std::cout<<count<<" "<<str.length()<<" "<<str.length()-count<<"\n";

counter=count;
//count=0;
    while(count<str.length() && str[count]!='"'){
        //counter++;
        count++;
    }
    for(int i=counter+1;i<str.length();i++){
        ord2.push_back(str[i]);
    }

    for (int i = 0; i < ord1.length(); i++) {
        if(ord1[i]== ' '){
            ord1.erase(i,1);
        }
        if(ord1[0]==' '){
            ord1.erase(0,1);
        }
        if(ord1[ord1.length()-1]== ' '){
            ord1.erase(ord1.length()-1,1);
        }
    }
    for (int j = 0; j < ord2.length(); j++) {
        if(ord2[j]==' '){
            ord2.erase(j,1);
        }
        if(ord2[0]==' '){
            ord2.erase(0,1);
        }
        if(ord2[ord2.length()-1]==' '){
            ord2.erase(ord2.length()-1,1);
        }

    }
    std::cout<<"ord1:"<<" "<<ord1<<ord1.length()<<"\n";
    std::cout<<"ord2:"<<" "<<ord2<<ord2.length()<<"\n";

}