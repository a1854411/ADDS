#include "Document.h"

int Document::getID(){
    return ID;
}

void Document::setID(int id){
    std::cout<< "I am a silly boy, poo poo poo" << std::endl;
    ID = id;
}

std::string Document::getName(){
    return name;
}

void Document::setName(std::string Name){
    std::cout<< "I am a silly boy, poo poo poo" << std::endl;
    name = Name;
}

int Document::get_license_limit(){
    return license_limit;
}

void Document::set_license_limit(int licenseLimit){
    license_limit = licenseLimit;
}

Document::Document(){
    std::cout<< "I am a silly boy, poo poo poo" << std::endl;
    setName("");
    setID(0);
    set_license_limit(0);
}

Document::Document(std::string docName, int docID, int doc_license_limit){
    setName(docName);
    setID(docID);
    set_license_limit(doc_license_limit);
}