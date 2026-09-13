#include "ReservationList.h"
#include <iostream>

using namespace std;


//Constructor
//Since this is an empty link and has no first link, head has to point nullptr
ReservationList::ReservationList() {
    head = nullptr;
    count = 0;
}

//Destructor to clean up the memory
ReservationList::~ReservationList() {
    Node* current = head;

    //The loop will go through each and every node
    //And delete the current node until the current node is nullptr
    while (current != nullptr) {
        Node* saveNext = current->next;
        delete current;
    }

    head = nullptr;
    count = 0;
}

// ================================================
// Insert
// ================================================
// Add a reservation at the Front of the list
// Before: head -> [B] -> [C] -> nullptr
// After: head -> [A] -> [B] -> [C] -> nullpyr

void ReservationList::insert(Reservation r){
    Node* newNode = new Node;    // 1. Create a brand new node 
    newNode->data = r; // This put the Reservation in the Node
    newNode->next = head;   // Connect the new Node to the old first Node 
    head = newNode;     //This make the newNode as a head

    count++;    //We count at each time we insert new reservation
}

// ================================================
// Remove
// Our remove function need to handle three cases:
// ================================================

bool ReservationList::remove(int reservationId){
    // Case 1: if list is empty
    // Nothing to remove so exit
    if (head == nullptr){
        return false;
    }


    // Case 2: if the match is the first link
    if (head->data.getReservationId() == reservationId) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }

    //Case3: if the match is somewhere after the first head
    Node* previous = head;
    Node* current = head->next;
    
    while (current != nullptr) {
        if (current->data.getReservationId() == reservationId) {
            previous->next = current->next;

            delete current;
        }
        //If there is no match 
        previous = current;
        current = current->next;        
    }
    return false;
}



