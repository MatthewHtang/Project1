#include "ReservationManager.h"
#include <iostream>

using namespace std;

// Constructor
// This runs when we create a ReservationManager object.
// We start reservation IDs from 1.
ReservationManager::ReservationManager() {
    nextReservationId = 1;
    // resources, activeReservations, cancellationHistory, and waitLists
    // all default-construct themselves — nothing else to set up here.
    //they are created automatically
}

// Destructor
// This runs when the ReservationManager object is destroyed.
// We do not need to manually delete anything here because
// the other classes handle their own memory.
ReservationManager::~ReservationManager() {
}

// Loads resource information from a file
// The ResourceManager class does the actual file reading.
bool ReservationManager::loadResourcesFromFile(const string& filename) {
    return resources.loadFromFile(filename);
}

// Displays all resources that are stored in the resource manager file
void ReservationManager::displayAllResources() {
    resources.displayAll();
}

// Displays information about one specific resource.
void ReservationManager::displayResourceAvailability(const string& resourceId) {
    Resource* r = findResource(resourceId);// Trying to find the resource using its ID.

    if (r == nullptr) { // nullptr means that the resource was not found.
        cout << "Resource not found: " << resourceId << endl;
        return;
    }

    r->display();
}

// Finds a resource using its ID
// It returns a pointer to the resource if it is found.
Resource* ReservationManager::findResource(const string& resourceId) {
    return resources.findById(resourceId);
}

// Checks if a resource can be reserved
// If findResource() finds the resource, this returns true.
// Otherwise, it returns false.
bool ReservationManager::validateReservation(const string& resourceId) {
    return findResource(resourceId) != nullptr;
}

// Creates a new reservation
bool ReservationManager::createReservation(int studentId, const string& studentName,
                                            const string& resourceId, const string& reservationDate) {
// First, make sure the resource ID actually exists.
    if (!validateReservation(resourceId)) {
        cout << "Invalid resource ID: " << resourceId << endl;
        return false;
    }
// Get the resource so we can check if it is available.
    Resource* resource = findResource(resourceId);
// If the resource is available, create the reservation.
    if (resource->isAvailable()) {

        int newId = nextReservationId; // Give this reservation a new unique ID.
        nextReservationId++; // Increase the ID so the next reservation gets a different number.

        Reservation newReservation(newId, studentId, studentName, resourceId, reservationDate);// Create a Reservation object using the student's information.
        insertReservation(newReservation); // Add the reservation to the active reservation list.

        resource->setAvailable(false);// The resource is now being used,
        // so we mark it as unavailable.
cout << "Reservation Created Successfully. Reservation ID: " << newId << endl;

    } else {

        addToWaitingList(studentId, studentName, resourceId);// If the resource is already reserved,
        // add the student to its waiting list.
        cout << "Resource " << resourceId << " is unavailable. "
             << studentName << " has been added to the waiting list." << endl;
    }

    return true;
}

// Cancels a reservation using its ID
bool ReservationManager::cancelReservation(int reservationId) {

    Reservation removed;// This object will store the reservation that gets removed.
    bool found = removeReservation(reservationId, removed);// Try to remove the reservation from the active reservation list.

    if (!found) {// If the reservation was not found, we cannot cancel it.
        cout << "Reservation not found: " << reservationId << endl;
        return false;
    }

    pushCancellation(removed);// Save the cancelled reservation in the cancellation history.
    cout << "Reservation Cancelled. Added to cancellation history." << endl;

    string resourceId = removed.getResourceId();// Get the resource ID from the cancelled reservation.

    int nextStudentId;// Get the resource ID from the cancelled reservation.
    string nextStudentName;

    if (removeFromWaitingList(resourceId, nextStudentId, nextStudentName)) {// Check if someone is waiting for this resource.

        int newId = nextReservationId;// Create a new reservation ID for the next student.
        nextReservationId++;

        Reservation autoAssigned(newId, nextStudentId, nextStudentName, // Automatically create a reservation for
        // the student who was first in the waiting list.
                                  resourceId, removed.getReservationDate());
        insertReservation(autoAssigned);// Add the new reservation to the active reservation list.

        cout << "Resource " << resourceId << " automatically assigned to "
             << nextStudentName << " (was next in line)." << endl;

   // We do not make the resource available here
        // because it was immediately given to the next student.

    } else {

        Resource* resource = findResource(resourceId);// If nobody is waiting, the resource becomes available again.
        if (resource != nullptr) {
            resource->setAvailable(true);
        }
    }

    return true;
}

// Displays all active reservations
void ReservationManager::displayActiveReservations() {
    activeReservations.displayAll();
}

// Adds a reservation to the linked list
void ReservationManager::insertReservation(const Reservation& newReservation) {
    activeReservations.insert(newReservation);
}

// Removes a reservation from the linked list
bool ReservationManager::removeReservation(int reservationId, Reservation& removedReservation) {
       Reservation* found = activeReservations.findById(reservationId);

    if (found == nullptr) {
        return false;
    }

    // copy the data out BEFORE removing — once remove() runs,
    // "found" points at memory that no longer belongs to us
    removedReservation = *found;

    activeReservations.remove(reservationId);
    return true;
}

// Goes through and displays the reservation list
void ReservationManager::traverseReservations() {
    activeReservations.displayAll();
}

// Adds a student to the end of the waiting list
void ReservationManager::addToWaitingList(int studentId, const string& studentName, const string& resourceId) {
    waitLists[resourceId].enqueue(studentId, studentName);
}

// Removes the first student from the waiting list for a resource
bool ReservationManager::removeFromWaitingList(const string& resourceId, int& studentId, string& studentName) {

    if (waitLists[resourceId].isEmpty()) {
        return false;
    }

    return waitLists[resourceId].dequeue(studentId, studentName);
}

// Displays all the students in the waiting list(s)
void ReservationManager::displayWaitingList() {

    if (waitLists.empty()) {
        cout << "No waiting lists yet." << endl;
        return;
    }

    bool anyWaiting = false;

    for (auto& entry : waitLists) {
        const string& resourceId = entry.first;
        WaitingList& list = entry.second;

        if (list.isEmpty()) {
            continue;
        }

        anyWaiting = true;
        cout << "\nWaiting list for " << resourceId << ":" << endl;
        list.displayAll();
    }

    if (!anyWaiting) {
        cout << "No one is currently waiting for any resource." << endl;
    }
}// Adds a cancelled reservation to the cancellation history
void ReservationManager::pushCancellation(const Reservation& cancelledReservation) {
    cancellationHistory.push(cancelledReservation);
}

// Restores the most recently cancelled reservation
bool ReservationManager::restoreLastCancellation() {

    Reservation restored;
    bool success = cancellationHistory.pop(restored);

    if (!success) {
        cout << "No cancellations to undo." << endl;
        return false;
    }

    insertReservation(restored);

    Resource* resource = findResource(restored.getResourceId());
    if (resource != nullptr) {
        resource->setAvailable(false);
    }

    cout << "Reservation Restored Successfully." << endl;
    return true;
}

// Displays the cancellation history
void ReservationManager::displayCancellationHistory() {
    cancellationHistory.displayAll();
}
