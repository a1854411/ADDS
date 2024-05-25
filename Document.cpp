#include "Document.h"

int Document::getID(){
    return ID;
}

void Document::setID(int id){
    ID = id;
}

std::string Document::getName(){
    return name;
}

void Document::setName(std::string Name){
    name = Name;
}

int Document::get_license_limit(){
    return license_limit;
}

void Document::set_license_limit(int licenseLimit){
    license_limit = licenseLimit;
}

int Document::get_number_borrowed(){
    return number_borrowed;
}

void Document::set_number_borrowed(int numberBorrowed){
    number_borrowed = numberBorrowed;
}

void Document::increment_number_borrowed(){
    number_borrowed = get_number_borrowed();
    number_borrowed++;
    set_number_borrowed(number_borrowed);
}

void Document::decrement_number_borrowed(){
    number_borrowed = get_number_borrowed();
    number_borrowed--;
    set_number_borrowed(number_borrowed);
}

Document::Document(){
    setName("");
    setID(0);
    set_license_limit(0);\
    set_number_borrowed(0);
}

Document::Document(std::string docName, int docID, int doc_license_limit){
    setName(docName);
    setID(docID);
    set_license_limit(doc_license_limit);
    set_number_borrowed(0);
}