#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

class Document {
    private:
        std::string name;
        int ID;
        int license_limit;
    public:
        int getID();
        void setID(int id);
        std::string getName();
        void setName(std::string Name);
        int get_license_limit();
        void set_license_limit(int licenseLimit);
        Document();
        Document(std::string docName, int docID, int doc_license_limit);
};

#endif