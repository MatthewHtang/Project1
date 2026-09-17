#include "CancellationHistory.h"
#include <iostream>

using namespace std;

/**
 *** Cancellation History ***
 */

// Constructor
CancellationHistory::CancellationHistory(){
    //Top is null
    top = nullptr;
    count = 0;
}

// Destructor
CancellationHistory::~CancellationHistory(){
    // We put a not 'current' on the top of the stack
    SNode* current = top;

    //if top is not nullptr (meaning if the list exist)
    if (top != nullptr){
        //save the third node from the top as 'saveNext'
        SNode* saveNext = top->next;
        delete current;     // Once we delete the current node
        current = saveNext;     // We say our saveNext is the current now
    }
    // Once the loop is done, it will reset the pointer and count
    top = nullptr;
    count = 0;
}

/**
 *** PUSH ***
 * Adds a calcelled reservation to the stack
 * 
 */
void CancellationHistory:: push(Reservation r){
    SNode* newNode = new SNode;     // Create a brand new Node
    newNode->data = r;      // We let that newNode's data to hold r (which is the whole reservation)

    newNode->next = top;    // Now we first point the newNode next as top
    //since newNode is safely connected to the newNode next, 
    // We can now take the top pointer and point it to the newNode
    top = newNode;

    count++;    // Counter
}
/**
 *** POP ***
 * Remove the top of the stack
 * 
 */
bool CancellationHistory:: pop(Reservation &r){
    // if top is nullptr, then nothing to remove
    if (top == nullptr){
        return false;
    }
    // We put a sticker called 'nodeToDelete' and put it on top of the first stack
    SNode* nodeToDelete = top;  

    //Hand the top data to a bucket before deleting the node
    r = nodeToDelete->data;

    //The one underneath become the top node
    top = top->next;

    //Now we can delete the data
    delete nodeToDelete;

    //Update the count
    count--;

    return true;
}

/**
 * PEEK
 * Nothing is remove in here, we will be just looking at whoever 
 * is on the top of the stack
 * 
 */
bool CancellationHistory::peek(Reservation &r){
    //If the stack is empty just return false
    if (top == nullptr){
        return false;
    }

    //If the stack is not empty
    //We take the top one's data and put it into a bucket
    // And return true
    r = top->data;

    return true;
}

/**
 * DISPLAY ALL
 * 
 */

void CancellationHistory::displayAll() {

    //If there is no cancellationHistory, just say no history to see
    if (top == nullptr){
        cout << "\nNo Cancellation History" << endl;
        return;
    }
    /**
     * Here we need a position again to list them
     */
    cout << "\n========== Cancellation History (" << count<< ") ==========" << endl;
    cout << "\n(most recent first -- undo restores #1)" << endl;

    SNode* current = top;    // We put a note called 'current' on the top
    int position = 1;       // Started counting

    //As long as we dont hit nullptr
    while (top != nullptr)
    {
        //Layout the position
        cout << position << ". ";
        current->data.display();

        // We change its pointer to the next node
        current = current->next;
        position++;     //increment again
    }
}
/**
 * EMPTY
 */
bool CancellationHistory::isEmpty(){
    // Just like we did in other program, 
    // it will return true if its empty, false if not
    return top == nullptr;  
}

/**
 * GET COUNT
 */
int CancellationHistory::getCount(){
    return count;  // Return the count
}
