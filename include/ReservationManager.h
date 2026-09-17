#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H
 
#include <string>
#include "Reservation.h"
using namespace std;
 // stores information about each resource
 struct Resource {
    string resourceId;// unique ID for the resource
    string name;// Name of the resource
    string type;//type of resource
    int totalQuantity;//total number available

    int availableQuantity;//number currently available
};
 //Node for reservation linked list
struct ReservationNode {
    Reservation data;//stores reservation information
    ReservationNode* next;//points to the next reservation

};
//node for the waiting list queue
struct WaitingNode {
    int studentId;//Student ID
    string studentName;// student name
    string resourceId;//resource the student is waiting for
    WaitingNode* next;//Points to the next reservation

};
 //Node for the cancellation history stack
struct CancellationNode {
    Reservation data;//stores the cancelled reservation

    CancellationNode* next;// points to the next cancelled reservation
};
 
class ReservationManager {
private:
    static const int MAX_RESOURCES = 100;
    //Array used to store resources
    Resource resources[MAX_RESOURCES];
    int resourceCount; //Number of resources currently stored        
//linked list for active reservations
    ReservationNode* reservationHead; //First reservation in the list  
    int reservationCount;  //Number of active reservations             
    int nextReservationId;   //ID for the next reservation

 
//Queue for students waiting for a resource
    WaitingNode* waitingFront;  // First student in the waiting list  
    WaitingNode* waitingRear;  // Last student in the waiting list
    int waitingCount;// Number of students waiting

 //stack used to keep cancellation history
    CancellationNode* cancellationTop;  
    int cancellationCount;
 
  //Finds a resource using its ID

    Resource* findResource(const string& resourceId); 
    //checks if a resource can be reserved      
    bool validateReservation(const string& resourceId);      
 
public:
//creates an empty reservation manager

    ReservationManager();
//cleans up dynamically allocated memory
    ~ReservationManager();
 //loads resource information from a file
    bool loadResourcesFromFile(const string& filename);   
    //Displays all resources

    void displayAllResources() const; 
    //shows availability  of a specific resource
void displayResourceAvailability(const string& resourceId) const; 

    bool createReservation(int studentId, const string& studentName, const string& resourceId, const string& reservationDate);// creates a new reservation

    bool cancelReservation(int reservationId);//cancels a reservation using its ID
    void displayActiveReservations() const;//displays all active reservations
 
    void insertReservation(const Reservation& newReservation);   // adds a reservation to the linked list         
    bool removeReservation(int reservationId, Reservation& removedReservation); // removes a reservation from the linked list 
    void traverseReservations() const; // goes through and displays the reservation list                                     
 
    void addToWaitingList(int studentId, const string& studentName, const string& resourceId); //adds a student to the end of the waitinglist
    bool removeFromWaitingList(WaitingNode*& removedNode);  // removes the first student from the waiting list                                    
    void displayWaitingList() const;// displays all the students in the waiting list
 
    void pushCancellation(const Reservation& cancelledReservation);   // adds a cancelled reservatiion to the cancellation history
    bool restoreLastCancellation();  //restores the most recently cancelled reservation                                  
    void displayCancellationHistory() const;//displays the cancellation history
};
 
#endif