// Add header guards to avoid compiler error
#ifndef CANCELLATIONHISTORY_H
#define CANCELLATIONHISTORY_H

#include "Reservation.h"    // We need to get the information from 

/**
 * Cancellation History
 * Stack must be used for cancellation tracking.
 * The implementation must support:
 * 
 * Store cancelled reservations
 * Restore the most recently cancelled reservation
 * Display cancellation history
 * 
 * This is what we will do, we since we are getting the recent 
 * cancelled reservation, we need to use Stack (LIFO)
 * 
 * 1) We need to struct a node 
 * 2) store the data and let the pointer point to the next node
 * 3) We need a class called CancellationHistory
 * 4) We only need one pointer, why? because this is a stack
 *    the student enters from top and exit from top. So, only one pointer 
 * 5) Constructor and destructor in public
 * 6) Push those canceled reservation into SNode
 * 7) Pop - to remove the top student on that stack
 * 8) Peek - to peek the first person on the top
 * 9) Display all
 * 10) getCount
 */

 struct SNode{      // Create a node called 'S', stands for Stack
    Reservation data;   // It holds the whole reservation data 
    SNode* next;        // It points it below, since it's a stack
 };

 class CancellationHistory{
    private:
    SNode* top;     //SNode pointing the top node
    int count;      // Count them
    
    public:
    //Constructor for cancellationHistory
    CancellationHistory();
    
    //Destructor for the cancellatoinHistory
    ~CancellationHistory();

    // Adds a cancelled reservation to the top of our SNode
    void push(Reservation r);

    //Remove the top of the reservation and writes it into r
    // Return true or false if the list is empty
    bool pop (Reservation &r);

    // Peek the top of the reservation without deleting it
    bool peek (Reservation &r);

    //Display all
    void displayAll();

    //Check if its empty or not?
    bool isEmpty();

    //Get the count
    int getCount();
 };
#endif
