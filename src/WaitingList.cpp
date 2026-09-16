#include "WaitingList.h"
#include <iostream>

using namespace std;

/**
 * Waiting List
 * 
 * Queue : Front and end pointers
 * Constructor: Front and end pointers pointing nullptr
 * Functions: Enqueue, Dequeue, Peek front, isEmpty, Display
 * 
 */

 // Constructor
 WaitingList::WaitingList() {
    front = nullptr;
    end = nullptr;
    count = 0;
 }

 // Destructor
 // Same pattern as ReservationList's destructor
 // saving next before deleting the current

 WaitingList::~WaitingList() {
    QNode* current = front;     // Current walks up first to the very first of the line

    while (current != nullptr){     // As long as current node is not nullptr
        QNode* saveNext = current->next;        // save the current next first
        delete current;     // Then delete the current 
        current = saveNext;     // Then declare the one we just saved to be current
    }
    front = nullptr;
    end = nullptr;
    count = 0;    
 }

 /**
  * Equeue
  * 
  * Adds a student to the back of the line
  * Here, we need two pointers, front and end. If we only have one pointer like 
  * a plain linked list, the complexity will be O(n), but two pointers allow
  * it to be O(1).
  * 
  */

  void WaitingList::enqueue (int studentId, string studentName){
    QNode* newNode = new QNode;     // Create a new QNode (A new student)

    // Now we are putting the actual student data like name and id 
    // in the Node we just created
    newNode->studentId = studentId; 
    newNode->studentName = studentName;

    // That node points to nullptr
    newNode->next = nullptr;

    // Case01: If nobody in the line at all
    if (end == nullptr){

        //This student is the entire line
        front = newNode;    // He is the front
        end = newNode;     // And the last
    }
    // Case02: if there is someone already in the line
    else {
        end->next = newNode;   // Take that first node pointer and point it to the newNode (new student's node)
        end = newNode;     // Now we change our end pointer to the new node we just added
    }

    count++;    // We count the number of new student we added
  }

  /**
  * Dequeue
  */

  