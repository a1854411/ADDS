#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

/////////// your code goes here... DO NOT change the function signatures ///////////

bool LinkedList::swap(int pos1, int pos2) { 
// swaps the data at positions pos1 and pos2 then returns true.
// If a or b are out-of-bounds, return false without swapping any elements.


    // if (pos1<1 || pos2<1 || head == nullptr){
    //     return false;
    // }


    // int aNum, bNum;
    // Node* a = new Node(aNum, nullptr);
    // Node* b = new Node(bNum, nullptr);

    // int a_previousdata, b_previousdata;
    // Node* a_previous = new Node(a_previousdata, a);
    // Node* b_previous = new Node(b_previousdata, b);

    // Node* a = a_previous->link;
    // Node* b = b_previous->link;

    // std::swap(a->data, b->data);

    return true;
}

bool LinkedList::find_and_delete(int target){
// searches the list for a node containing target, which then deletes it and returns true. [3 marks]
// If target appears multiple times in the list, delete the first occurrence.
// If target does not exist in the list return false.

    for (Node* currNode = head; currNode != nullptr; currNode = currNode->link){
        if(currNode->data == target){
            
            Node* temp = currNode->link;
            currNode->link = temp->link;
            delete temp;

            return true;
        }
    }
    return false;
}