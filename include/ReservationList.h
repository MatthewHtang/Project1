// Incldue header guards to avoid compiler error
#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H

#include "Reservation.h"

// A Node is one link in the chain.
// It holds the reservation, and the address of the next link.

struct Node{    //Create Node
  Reservation data;   //Store data and the reservation addrs
  Node* next;   //Next pointer
};

class ReservationList {

  private:
  Node* head;   //Head point to the first Node, (if empty, nullptr )
  int count;   // Keep track of how many reservations are currently in the list

  public:
  ReservationList();    //Constructor - runs automatically when the list is created
  ~ReservationList();   // Destructor - runs automatically when the list is destroyed

  void insert(Reservation r);   //This function adds reservation to the list
  bool remove(int reservationId);   //This function removes a reservation based on its ID
  Reservation* findById(int reservationId);   //This function searches the linked list for a reservation
  Reservation* FindByStudentId(int studentId);   //This function searches the linked list for a reservation by student ID
  Reservation* FindByResourceId(string resourceId);   //This function searches the linked list

  void displayAll();    //This function will print every reservation
  bool isEmpty();   //This checks whether the list has anything inside it
  int getCount();   //  To get the number of reservation

  // Counts how many active reservations belong to a specific resource
  int countByResourceId(const string& resourceId);

  //Linear search: prints every match, return how many
  int displayByStudentId(int studentId);
};
#endif