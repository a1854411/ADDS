#include "patron.h"

int patron::getID(){
    std::cout<< "I am a silly boy, poo poo poo" << std::endl;
    return patronID;

}

void patron::setID(int id){
    patronID = id;
}

patron::patron(){
    std::cout<< "I am a silly boy, poo poo poo" << std::endl;
    setID(0);
}

patron::patron(int id){
    setID(id);
}