#include "LinkedList.h"
#include <limits>
using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
}

// LinkedList::LinkedList(int* array, int len){
//     Node* current_node= new Node(array[0], nullptr);
//     head = current_node;

//     for(int i=1; i<len; i++){
//         Node* new_node= new Node(array[i], nullptr);
//         current_node->link = new_node;
//         current_node = new_node;
//     }
// }

LinkedList::LinkedList(int* array, int len) {
    head = nullptr;
    for (int i=0; i < len; i++) {
        insertPosition(i+1, array[i]);}
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->link;
        delete temp;}
}


// void LinkedList::printList(){
//     Node* current_node = head;

//     std::cout << "[";
//     while(current_node != nullptr){
//         std::cout << current_node->data; 
//         current_node = current_node->link;
//     }
//     std::cout << "]";
// }

void LinkedList::printList() {
    std::cout << '[';
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->link != nullptr) cout << ' ';
        current = current->link;}
    cout << ']' << endl;
}


// void LinkedList::insertPosition(int pos, int newNum){
//     if(pos <= 1){
//         head = new Node(newNum, head);
//         return;
//     }

//     Node* current_node = head;

//     for(int i=2; i<(pos-1); i++){
//         if(current_node->link == nullptr){
//             Node* new_node = new Node(newNum, nullptr);
//             current_node->link = new_node;
//             return;
//         }
//         Node* new_node = new Node(newNum, current_node->link);
//         current_node = current_node->link;
//         current_node->link = new_node;

//     }
// }

void LinkedList::insertPosition(int pos, int newNum) {
    Node* new_node = new Node(newNum, nullptr);
    if(pos <= 1 || head == nullptr){
        new_node->link = head;
        head = new_node;}
    else{
        Node* current_node = head;
        for (int i=1; i < pos - 1 && current_node->link != nullptr; i++) {
            current_node = current_node->link;}
        new_node->link = current_node->link;
        current_node->link = new_node;
    }
}

// bool LinkedList::deletePosition(int pos){
//     if (pos <= 0 || head == nullptr){ // Check for invalid position or empty list
//         return false;
//     }

//     Node* current_node = head;
//     Node* previous_node = nullptr;

//     //delete at start
//     if(pos == 1){
//         head = current_node->link; //set head to next node
//         delete current_node;
//         return true;
//     }

//     //traverse the list
//     for(int i=2; current_node!=nullptr && i<(pos-1); i++){
//         previous_node = current_node;
//         current_node = current_node->link;
//     }
//         // If position exceeds the size of the list
//         if (current_node == nullptr){
//             return false;
//         }

//         previous_node->link = current_node->link;
//         delete current_node;

//         return true;
// }

bool LinkedList::deletePosition(int pos) {
    if (pos<1 || head == nullptr) {
        return false;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->link;
        delete temp;
    }else{
        Node* current_node = head;
        for (int i = 1; i < pos - 1 && current_node != nullptr; i++) {
            current_node = current_node->link;
    }
        
    if (current_node == nullptr || current_node->link == nullptr) {
        return false;
    }
        
    Node* temp = current_node->link;
    current_node->link = temp->link;
    delete temp;
    }
    return true;
}


int LinkedList::get(int pos){
    if (pos < 1 || this->head == nullptr) {
        return std::numeric_limits<int>::max();}

    Node* current_node = this->head;
    for (int i = 1; i < pos && current_node != nullptr; i++) {
        current_node = current_node->link;}

    if (current_node == nullptr) {
        return std::numeric_limits<int>::max();}

    return current_node->data;
}


int LinkedList::search(int target){
    int index = 1;
    for (Node* current_node = head; current_node != nullptr; current_node = current_node->link) {
        if (current_node->data == target) {
            return index;}
        index++;}
    return -1;
}

