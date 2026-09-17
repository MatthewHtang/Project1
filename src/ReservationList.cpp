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
        Node* saveNext = current->next; //1. Save the next Node
        delete current; //2. Delete the current Node
        current = saveNext; // 3. Now the current Node is the second Node
    }

    // Declare that our list is completely empty now
    head = nullptr;
    count = 0;
}

// ================================================
// Insert
// ================================================
// This is what it should looks like
// Before: head -> [B] -> [C] -> nullptr
// After: head -> [A] -> [B] -> [C] -> nullpyr

void ReservationList::insert(Reservation r) {

    Node* newNode = new Node;    // Create a brand new node 
    newNode->data = r; // This put the Reservation in the Node

    // Scenario 1: If there is no reservation
    if (head == nullptr){
        newNode->next = nullptr;    // New node points to nothing
        head = newNode;     // Head points to new Node
    }

    // Scenario 2: If there is reservation lists already
    else {
        newNode->next = head;   // First, the new Node points to the head which is the previous fist Node
        head = newNode;     // Since we linked the new Node with the rest, we now declare new Node to be Head
    }

    count++;    //We count at each time we insert new reservation
}

// ================================================
// Remove
// Remove function need to handle three cases:
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
        head = head->next;  // This move the head to the second Node
        delete nodeToDelete;    // This delete the previous head Node (which is the fist Node)

        count --;   // This update the total
        return true;
    }

    //Case3: if the match is somewhere after the first head
    Node* previous = head;  // Declare the head to be previous
    Node* current = head->next; // Declare the second Node to be current
    
    while (current != nullptr) {

        // First did the current pointer find the match?
        if (current->data.getReservationId() == reservationId) {

            // We skip the current Node
            previous->next = current->next;

            // Destroy the current Node from the memory
            delete current;

            count --;
            return true;
        }
        //If there is no match 
        previous = current;
        current = current->next;        
    }
    // If the reservation ID is not the reservation list
    return false;
}

// ================================================
// Find By Reservationn ID
// As long as the current is not nullptr, it will skim through the whole Nodes
// If found, it will return the data of that Node
// ================================================

Reservation* ReservationList::findById(int reservationId) {

    Node* current = head;   // Declare head as current

while (current != nullptr) {

    // If the current reservation id is what we are looking for
    if(current->data.getReservationId() == reservationId) {
        
        // We will return that Node data
        return &(current->data);
    }
    // Move forward to check
    current = current->next;
}
return nullptr;
}

// ================================================
// Display All
// ================================================
void ReservationList::displayAll() {

    if (head == nullptr) {
        cout << "\nThere is no active reservations." << endl;
        return;
    }

    // Displaying how much reservation we have in total
    cout << "\n===== Active Reservations (" << count << ") =====" << endl;

    Node* current = head;

    while (current != nullptr) {
        // Display each and every reservation data
        current->data.display();

        // And move forward
        current = current->next;
    }
}

// ================================================
// Is Empty
// If the list is empty, it directly return true, if not, false
// ================================================
bool ReservationList::isEmpty() {
    return head == nullptr;
}

// ================================================
// Get Count
// Get the total number of reservation after add/remove
// ================================================
int ReservationList::getCount() {
    return count;
}


