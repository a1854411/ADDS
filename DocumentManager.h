#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include "Document.h"
#include "patron.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


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
        //if document patronID is in borrowedDocuments & number_borrowers < liscense index{
        // add docid to borrowed documents linked to patronID
        // doc.number_borrowers++ 
        //}

            // Check if the document exists
            auto docIt = Documents.find(docid);
            if (docIt == Documents.end()) {
                cout << "Document ID " << docid << " not found." << endl;
                return false;
            }

            // Check if the patron exists
            auto patronIt = borrowedDocuments.find(patronID);
            if (patronIt == borrowedDocuments.end()) {
                cout << "Patron ID " << patronID << " not found." << endl;
                return false;
            }

            Document* doc = docIt->second;

            // Check if the document can be borrowed
            if (doc->get_number_borrowed() >= doc->get_license_limit()) {
                cout << "Document ID " << docid << " has reached its license limit." << endl;
                return false;
            }

            // Add the document ID to the list of borrowed documents for the patron
            patronIt->second.push_back(docid);
            doc->increment_number_borrowed();

            cout << "Document ID " << docid << " successfully borrowed by patron ID " << patronID << "." << endl;
            return true;
        }
 
        void returnDocument(int docid, int patronID){
                // Check if the document exists
    auto docIt = Documents.find(docid);
    if (docIt == Documents.end()) {
        cout << "Document ID " << docid << " not found." << endl;
        return;
    }
    
    // Check if the patron exists
    auto patronIt = borrowedDocuments.find(patronID);
    if (patronIt == borrowedDocuments.end()) {
        cout << "Patron ID " << patronID << " not found." << endl;
        return;
    }
    
    // Check if the patron has borrowed the document
    auto& borrowedDocs = patronIt->second;
    auto borrowedDocIt = std::find(borrowedDocs.begin(), borrowedDocs.end(), docid);
    if (borrowedDocIt == borrowedDocs.end()) {
        cout << "Patron ID " << patronID << " has not borrowed Document ID " << docid << "." << endl;
        return;
    }
    
    // Remove the document ID from the patron's borrowed list
    borrowedDocs.erase(borrowedDocIt);
    
    // Decrement the number of borrowers for the document
    Document* doc = docIt->second;
    doc->decrement_number_borrowed();
    
    cout << "Document ID " << docid << " successfully returned by Patron ID " << patronID << "." << endl;
        }
};

#endif