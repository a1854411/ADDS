#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

class Document {
    private:
        std::string name;
        int ID;
        int license_limit;
        int number_borrowed;

    public:
        int getID();
        void setID(int id);
        std::string getName();
        void setName(std::string Name);
        int get_license_limit();
        void set_license_limit(int licenseLimit);
        int get_number_borrowed();
        void set_number_borrowed(int numberBorrowers);
        void increment_number_borrowed();
        void decrement_number_borrowed();
        Document();
        Document(std::string docName, int docID, int doc_license_limit);
};

#endif