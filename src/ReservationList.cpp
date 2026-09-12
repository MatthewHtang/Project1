#include "ReservationList.h"
#include <iostream>

using namespace std;


//Constructor
//This is an empty link and has no first link and holds nothing
ReservationList::ReservationList() {
    head = nullptr;
    count = 0;
}

//Destructor to clean up the memory
ReservationList::~ReservationList() {
    Node* current = head;

    while (current != nullptr) {
        Node* saveNext = current->next;
        delete current;
    }

    head = nullptr;
    count = 0;
}

//Insert
//Add a reservation at the Front of the list
//Before: head -> [B] -> [C] -> nullptr
//After: head -> [A] -> [B] -> [C] -> nullpyr

void ReservationList::insert(Reservation r){
    Node* newNode = newNode;    // Build the link
    newNode->data = r;

    newNode->next = head;   
    head = newNode;

    count++;
}

