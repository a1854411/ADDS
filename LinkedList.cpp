#include "LinkedList.h"

LinkedList::LinkedList(){
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len){
    Node* current_node= new Node(array[0], nullptr);
    head = current_node;

    for(int i=1; i<len; i++){
        Node* new_node= new Node(array[i], nullptr);
        current_node->link = new_node;
        current_node = new_node;

    }
}


void LinkedList::printList(){
    Node* current_node = head;

    std::cout << "[";
    while(current_node != nullptr){
        std::cout << current_node->data; 
        current_node = current_node->link;
    }
    std::cout << "]";
}


void LinkedList::insertPosition(int pos, int newNum){
    if(pos <= 1){
        head = new Node(newNum, head);
        return;
    }

    Node* current_node = head;

    for(int i=2; i<(pos-1); i++){
        if(current_node->link == nullptr){
            Node* new_node = new Node(newNum, nullptr);
            current_node->link = new_node;
            return;
        }
        Node* new_node = new Node(newNum, current_node->link);
        current_node = current_node->link;
        current_node->link = new_node;

    }
}

bool LinkedList::deletePosition(int pos){
    if(pos <= 1){
        Node* current_node = head;
        head = head->link;
        delete current_node;

        return true;
    }

    for(int i=2; i<(pos-1); i++){
        if(current_node->link == nullptr){
            Node* temp = head;
            head = head->link;
            delete temp;

            return true;
        }



    }

}


int LinkedList::get(int pos){

}


int LinkedList::search(int target){

}
