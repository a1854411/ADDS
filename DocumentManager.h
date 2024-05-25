#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include "Document.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class DocumentManager {
    private:
        unordered_map<int, Document*> Documents; // Using map with document ID as key
        unordered_map<int, vector<int>> borrowedDocuments; // Maps patronID to list of borrowed document IDs
    public:
        void addDocument(string name, int id, int license_limit) {
            Document* doc = new Document(name, id, license_limit);
            Documents.emplace(id, doc);
        }

        void addPatron(int patronID) {
            borrowedDocuments.emplace(patronID, vector<int>());
        }

        int search(string name) { // returns docid if name is in the document collection or 0 if the name is not in the collection
            for (const auto& pair : Documents) {
                if (pair.second->getName() == name) {
                    return pair.first; // Return the document ID if name matches
                }
            }
            return 0; // Return 0 if name is not found
        }

        bool borrowDocument(int docid, int patronID) { // returns true if document is borrowed, false if it cannot be borrowed (invalid patronID or the number of copies currently borrowed has reached the license limit)
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

        void returnDocument(int docid, int patronID) {
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
            auto borrowedDocIt = find(borrowedDocs.begin(), borrowedDocs.end(), docid);
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

#endif // DOCUMENTMANAGER_H