#include "patron.h"

int patron::getID(){
    return patronID;

}

void patron::setID(int id){
    patronID = id;
}

patron::patron(){
    setID(0);
}

patron::patron(int id){
    setID(id);
}