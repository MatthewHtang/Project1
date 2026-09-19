#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H
#include <string>// allows us to use string for storing data
#include <map>//allows us to use map, a map stores information using a key
//These are other files and classes used by reservationmanager
#include "Reservation.h"// stores information about one reservation
#include "Resource.h"// stores information about one resource
#include "ResourceManager.h"// manages all the resources
#include "ReservationList.h"// manages the list of active reservations
#include "WaitingList.h"// manages students waiting for a resource
#include "CancellationHistory.h" // stores cancelled reservations
using namespace std;
//reservationmanager is the main class that manages reservations, it connects resources, reservations, waitinglists, and cancellation history
class ReservationManager {
private:
    ResourceManager resources; //stores and manages all resources            
    ReservationList activeReservations; // stores all reservations that are currently active
    CancellationHistory cancellationHistory; // stores reservations that have been cancelled and also allows us to keep a history of cancellations and restore the most recently cancelled reservation

    map<string, WaitingList> waitLists;// stores a separate waiting list for each resource, the resource ID is used to find its waiting list

    int nextReservationId; //stores the ID that will be given to the next reservation
    Resource* findResource(const string& resourceId);// searches for a resource using its resource ID and if the resource is found, it returns a pointer to that resource object and if it is not found, it can return nullptr
    bool validateReservation(const string& resourceId);//checks whether a resource can currently be reserved, it returns true if the reservation is allowed and returns false if the resource cannot be reserved

public:
    // constructor//this function automatically runs when a reservationmanager object is created, it is used to set the starting values such a sstarting nextreservationID at 1
    ReservationManager();
     ~ReservationManager();// destructor// this function automatically runs when the reservationmanager object is destroyed.// we do not need to manually delete the members here because the other classes clean themselves up.
     bool loadResourcesFromFile(const string& filename);// reads resource information from a file, the "filename" tells the program which file to read, it returns true if the file loads successfully and returns false if the file cannot be loaded

    void displayAllResources();// displays all resources stored in the system,this shows things such as: resourceID, resource name, type,and availability

    void displayResourceAvailability(const string& resourceId);// displays information about one specific resource, the resource ID tells the program which resource we want to check

    bool createReservation(int studentId, const string& studentName,
                            const string& resourceId, const string& reservationDate);// creates a new reservation for a student.

    bool cancelReservation(int reservationId);// cancels an existing reservation and the reservation ID tells the program which reservation should be cancelled


    void displayActiveReservations();// displays all reservations that are currently active

    void insertReservation(const Reservation& newReservation);//adds a new reservation to the active reservation list; a new reservation contains all information about the reservation being added

    bool removeReservation(int reservationId, Reservation& removedReservation);// removes a reservation from the active reservation list
    // reservationId tells the program which reservation to remove and the removed Reservation is used to save a copy of the reservation that was removed.

    void traverseReservations();// goes through the active reservation list and displays the reservations one by one

    void addToWaitingList(int studentId, const string& studentName, const string& resourceId);// adds a student to the waiting list for a resource, this can be used when a resource is not currently available.

    bool removeFromWaitingList(const string& resourceId, int& studentId, string& studentName);//removes the first student from a resource's waitinglist, the waitinglist works like a line: the first student added is the first student removed
    // resourceid tells us which waiting list to use.
    //student ID and student name are used to return the information about the student who was removed and it returns false if the waiting list was empty

    void displayWaitingList();// displays the students who are in the waiting list waiting for the resources

    void pushCancellation(const Reservation& cancelledReservation);//adds s cancelled reservation to the cancellation history. This keeps a record of reservations that have been cancelled

    bool restoreLastCancellation();// restores the most recently cancelled reservation and returns true if a cancelled reservation was successfully restored and returns false if there is nothing to restore 
    void displayCancellationHistory();// displays the history of cancelled reservations.
};

#endif