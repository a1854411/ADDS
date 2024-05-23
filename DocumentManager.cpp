#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit){
            Document doc(name, id, license_limit);
            Documents.emplace(doc);
}
void DocumentManager::addPatron(int patronID){}
int DocumentManager::search(std::string name){} // returns docid if name is in the document collection or 0 if the name is not in the collection
bool DocumentManager::borrowDocument(int docid, int patronID){}  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
void DocumentManager::returnDocument(int docid, int patronID){}