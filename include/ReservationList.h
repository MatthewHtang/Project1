//First we need a header guards to avoid compiler error
#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H

#include "Reservation.h"

 /**
  * ReservationList
  * 
  * Singly linked list will be use to store all the active reservations
  * Insertion will begin from the head
  * 
  * Since we don't have anything from the Reservation yet, 
  * let's just assume that the Reservation provide
  * - default constructor
  * - int getReservationId () const
  * - void display() const
  *
  * *This is subject to change depending on how Reservation is structured 
  */

  class ReservationList{
    private:
    struct Node {    //Create a Node
        Reservation data;   //Each Node contains a reservation
        Node* next;     //Next pointer

        //Constructor for Node
        Node(const Reservation& r) : data(r), next(nullptr){};


    };

  };

#endif