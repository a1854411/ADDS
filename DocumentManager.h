#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include "Document.h"
#include "patron.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


class DocumentManager {
    private:
        std::unordered_map<int, Document*> Documents; // Using map with document ID as key
        std::unordered_map<int, std::vector<int>> borrowedDocuments; // Maps patronID to list of borrowed document IDs
    public:
        void addDocument(std::string name, int id, int license_limit){
            Document doc(name, id, license_limit);
            Documents.emplace(doc);
        }

        void addPatron(int patronID){
            patron pat(patronID);
            borrowedDocuments.emplace(pat);
        }

        int search(std::string name){ // returns docid if name is in the document collection or 0 if the name is not in the collection
            for (const auto& pair : Documents) {
                if (pair.second->getName() == name) {
                    return pair.first; // Return the document ID if name matches
                }
            }  
            return 0; // Return 0 if name is not found
        }

        bool borrowDocument(int docid, int patronID){  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
        //if document patronID is in borrowedDocuments{
        // add docid 
        std::cout<< "I am a silly boy, poo poo poo" << std::endl;
        //}
        }

        void returnDocument(int docid, int patronID){

        }
};

#endif