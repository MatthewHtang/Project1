#include "WaitingList.h"
#include <iostream>

using namespace std;

/**
 * Waiting List
 * 
 * Queue : Front and end pointers
 * Constructor: Front and end pointers pointing nullptr
 * Functions: Enqueue, Dequeue, Peek front, isEmpty, Display, getCount
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
  * Enqueue
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
  * 
  * Remove the student from the front of the line
  * 
  * Case01: if nobody is waiting, then just return false
  * This is what we are going to do:
  *     * First declare the first node as 'nodeToDelete'
  *     * Save the two data into a bucket before deleting
  *     * Change the front pointer to point the next node
  *     * Now our front and end pointers pointing
  *       towards the second Node. Now what if we also dequeue 
  *       the second Node, front pointer will point to nullptr but
  *       what about our end pointer?(We need to reset the pointers when
  *       the front pointer become nullptr)
  *     * delete the Node
  *     * update the counter
  *     * return true
  *
  */

 bool WaitingList::dequeue(int &studentId, string &studentName){

    // Case01: If no one is waiting
    if (front == nullptr){
        return false;
    }

    // This is like putting a sticky notes on the first node saying, 
    // 'This is the node we are going to delete'
    QNode* nodeToDelete = front;

    // Before we delete it, we need to hand the two data in to a bucket
    studentId = nodeToDelete->studentId;
    studentName = nodeToDelete->studentName;

    // Now we change the front pointer to the Next Node
    front = front->next;

    // Reset the pointers when the front hits at null ptr
    if (front == nullptr){
        end = nullptr;
    }

    // Now everything is safe, we can delete the node we put the sticker on
    delete nodeToDelete;
    
    // Update the counter
    count--;

    return true;
 }

 /**
  * Peek Front
  * We will be just looking at whoever is in the first line
  */
 bool WaitingList::peekFront(int &studentId, string &studentName){
    
    //If the queue is empty, just return false
    if (front == nullptr){
        return false;
    }

    //Put the Node data into a bucket
    studentId = front->studentId;
    studentName = front->studentName;

    return true;
}

/**
 * Display All the WaitingList
 * 
 * Walk from the front to end and print every student's data in line
 * Case01: If no one is waiting
 * Case02: if there is aline
 * 
 * What to do:
 * 1) Put a note called current on a the front node
 * 2) cout the student
 * 3) set the current to current->next
 */
void WaitingList::displayAll() {
    //Case01: If the line is empty
    if(front == nullptr){
        cout << "(There is no one in line)" << endl;
        return;
    }

    //Case02: if there is a line
    // Set front as current
        QNode* current = front;
        int position = 1; // We need to number the list

        while (current != nullptr){
            cout << " " << position << ". " 
            << current->studentName << " (ID: " << current->studentId << ")" << endl;
            
            current = current->next;    // Set the current to the next node
            position ++;    // Increment the number for the list
        }
}

/**
 * isEmpty
 * Check if the WaitingList is empty or not
 * Then return True is front pointer is null ptr and False if not
 */

 bool WaitingList::isEmpty(){
    return front == nullptr;
 }

 /**
  * getCount
  * Update how many students are in the waiting list
  */

  int WaitingList::getCount(){
    return count;
  }



  