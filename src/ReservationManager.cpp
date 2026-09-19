#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// CONSTRUCTOR
// This function runs automatically when we create
// a ReservationManager object.
// It gives starting values to all variables.
ReservationManager::ReservationManager() {

    // At the beginning, we have no resources loaded
    resourceCount = 0;

    // The reservation linked list is empty,
    // so the head does not point to anything
    reservationHead = nullptr;

    // No active reservations at the beginning
    reservationCount = 0;

    // The first reservation will have ID 1
    nextReservationId = 1;

    // The waiting queue is empty,
    // so both front and rear are nullptr
    waitingFront = nullptr;
    waitingRear = nullptr;

    // No students are waiting yet
    waitingCount = 0;

    // The cancellation stack is empty
    cancellationTop = nullptr;

    // No cancelled reservations yet
    cancellationCount = 0;
}
// DESTRUCTOR
// This function runs automatically when the
// ReservationManager object is destroyed.
// We delete dynamically created nodes to free memory.
ReservationManager::~ReservationManager() {

    // Delete all nodes from the reservation linked list
    while (reservationHead != nullptr) {

        // Save the current first node
        ReservationNode* temp = reservationHead;

        // Move head to the next node
        reservationHead = reservationHead->next;

        // Delete the old node
        delete temp;
    }

    // Delete all nodes from the waiting list queue
    while (waitingFront != nullptr) {

        // Save the first waiting node
        WaitingNode* temp = waitingFront;

        // Move front to the next student
        waitingFront = waitingFront->next;

        // Delete the old node
        delete temp;
    }

    // Delete all nodes from cancellation stack
    while (cancellationTop != nullptr) {

        // Save the top node
        CancellationNode* temp = cancellationTop;

        // Move top to the next node
        cancellationTop = cancellationTop->next;

        // Delete old top node
        delete temp;
    }
}
// FIND RESOURCE
// Searches the resource array using the resource ID.
// Returns the address of the resource if found.
// Returns nullptr if the resource does not exist.
Resource* ReservationManager::findResource(
    const string& resourceId) {

    // Go through all resources stored in the array
    for (int i = 0; i < resourceCount; i++) {

        // Compare the resource ID
        if (resources[i].resourceId == resourceId) {

            // Return the address of the matching resource
            return &resources[i];
        }
    }

    // Resource was not found
    return nullptr;
}
// VALIDATE RESERVATION
// Checks if a resource exists and if at least
// one of that resource is available.
bool ReservationManager::validateReservation(
    const string& resourceId) {

    // Search for the resource
    Resource* resource = findResource(resourceId);

    // nullptr means the resource was not found
    if (resource == nullptr) {
        return false;
    }

    // If quantity is 0 or less,
    // the resource cannot be reserved
    if (resource->availableQuantity <= 0) {
        return false;
    }

    // Resource exists and is available
    return true;
}
// LOAD RESOURCES FROM FILE
// Opens a file and stores resource information
// inside the resources array.

bool ReservationManager::loadResourcesFromFile(
    const string& filename) {

    // Try to open the file
    ifstream file(filename);

    // Check if the file opened successfully
    if (!file.is_open()) {
        cout << "Could not open resource file." << endl;
        return false;
    }

    // Start storing resources from index 0
    resourceCount = 0;

    string line;

    // Read one line at a time.
    // Also make sure we do not go over MAX_RESOURCES.
    while (getline(file, line) &&
           resourceCount < MAX_RESOURCES) {

        // Ignore empty lines
        if (line.empty()) {
            continue;
        }

        // stringstream helps separate the line
        // using commas
        stringstream ss(line);

        string id;
        string name;
        string type;
        string quantity;

        // Read resource ID until comma
        getline(ss, id, ',');

        // Read resource name until comma
        getline(ss, name, ',');

        // Read resource type until comma
        getline(ss, type, ',');

        // Read the remaining value as quantity
        getline(ss, quantity);

        // Store the information in the array
        resources[resourceCount].resourceId = id;
        resources[resourceCount].name = name;
        resources[resourceCount].type = type;

        // stoi changes a string into an integer
        // Example: "5" becomes 5
        try {
            resources[resourceCount].totalQuantity =
                stoi(quantity);
        }
        catch (...) {

            // If quantity cannot be converted to a number
            cout << "Invalid quantity in resource file."
                 << endl;

            // Skip this resource
            continue;
        }

        // At the beginning, all resources are available.
        // So available quantity equals total quantity.
        resources[resourceCount].availableQuantity =
            resources[resourceCount].totalQuantity;

        // Move to the next position in the array
        resourceCount++;
    }

    // Close the file after reading
    file.close();

    cout << "Resources loaded successfully." << endl;

    return true;
}
// DISPLAY ALL RESOURCES
// Shows all resources stored in the resource array.
void ReservationManager::displayAllResources() const {

    // If no resources were loaded
    if (resourceCount == 0) {
        cout << "No resources available." << endl;
        return;
    }

    cout << "\n--- Resource List ---" << endl;

    // Go through every resource
    for (int i = 0; i < resourceCount; i++) {

        cout << "Resource ID: "
             << resources[i].resourceId << endl;

        cout << "Name: "
             << resources[i].name << endl;

        cout << "Type: "
             << resources[i].type << endl;

        cout << "Total Quantity: "
             << resources[i].totalQuantity << endl;

        cout << "Available Quantity: "
             << resources[i].availableQuantity << endl;

        cout << "---------------------" << endl;
    }
}
// DISPLAY RESOURCE AVAILABILITY
// Searches for one resource and displays
// how many are currently available.
void ReservationManager::displayResourceAvailability(
    const string& resourceId) const {

    // Search through the resource array
    for (int i = 0; i < resourceCount; i++) {

        // Check if the ID matches
        if (resources[i].resourceId == resourceId) {

            cout << "Resource: "
                 << resources[i].name << endl;

            cout << "Available Quantity: "
                 << resources[i].availableQuantity << endl;

            // Stop after finding the resource
            return;
        }
    }

    // If loop finishes without finding it
    cout << "Resource not found." << endl;
}
// CREATE RESERVATION
// Creates a new reservation for a student.
// If the resource is unavailable, the student
// is added to the waiting list.
bool ReservationManager::createReservation(
    int studentId,
    const string& studentName,
    const string& resourceId,
    const string& reservationDate) {

    // First search for the resource
    Resource* resource = findResource(resourceId);

    // Check if resource exists
    if (resource == nullptr) {
        cout << "Resource not found." << endl;
        return false;
    }

    // Check if the resource is available
    if (!validateReservation(resourceId)) {

        cout << "Resource is currently unavailable."
             << endl;

        cout << "Student added to waiting list."
             << endl;

        // Put the student at the end of the waiting queue
        addToWaitingList(
            studentId,
            studentName,
            resourceId
        );

        return false;
    }

    // Create a Reservation object
    // using the next available reservation ID
    Reservation newReservation(
        nextReservationId,
        studentId,
        studentName,
        resourceId,
        reservationDate
    );

    // Add reservation to linked list
    insertReservation(newReservation);

    // One resource was reserved,
    // so reduce available quantity by 1
    resource->availableQuantity--;

    cout << "Reservation created successfully."
         << endl;

    cout << "Reservation ID: "
         << nextReservationId << endl;

    // Increase ID so next reservation
    // gets a different ID
    nextReservationId++;

    return true;
}
// CANCEL RESERVATION
// Removes an active reservation.
// The cancelled reservation is also saved
// in the cancellation stack.
bool ReservationManager::cancelReservation(
    int reservationId) {

    // This variable will store the reservation
    // that gets removed
    Reservation removedReservation;

    // Try to remove the reservation
    if (!removeReservation(
            reservationId,
            removedReservation)) {

        cout << "Reservation not found." << endl;

        return false;
    }

    // Save cancelled reservation in cancellation history
    pushCancellation(removedReservation);

    // Find the resource connected to the reservation
    Resource* resource =
        findResource(
            removedReservation.getResourceId()
        );

    // If resource exists, one item becomes available again
    if (resource != nullptr) {
        resource->availableQuantity++;
    }

    cout << "Reservation cancelled successfully."
         << endl;

    return true;
}
// DISPLAY ACTIVE RESERVATIONS
// Goes through the reservation linked list
// and displays each active reservation.
void ReservationManager::displayActiveReservations() const {

    // Check if linked list is empty
    if (reservationHead == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }

    cout << "\n--- Active Reservations ---" << endl;

    // Start from the first node
    ReservationNode* current = reservationHead;

    // Continue until we reach the end of the list
    while (current != nullptr) {

        // Display the Reservation stored in this node
        current->data.display();

        cout << "---------------------------"
             << endl;

        // Move to the next node
        current = current->next;
    }
}
// INSERT RESERVATION
// Adds a new reservation to the END
// of the reservation linked list.
void ReservationManager::insertReservation(
    const Reservation& newReservation) {

    // Dynamically create a new node
    ReservationNode* newNode =
        new ReservationNode;

    // Store reservation inside the node
    newNode->data = newReservation;

    // Since this will be the last node,
    // next starts as nullptr
    newNode->next = nullptr;

    // If the linked list is empty,
    // newNode becomes the first node
    if (reservationHead == nullptr) {

        reservationHead = newNode;
    }
    else {

        // Start at the beginning of the list
        ReservationNode* current =
            reservationHead;

        // Keep moving until we reach last node
        while (current->next != nullptr) {

            current = current->next;
        }

        // Connect the old last node
        // to the new node
        current->next = newNode;
    }

    // Increase number of active reservations
    reservationCount++;
}
// REMOVE RESERVATION
// Searches for a reservation using its ID
// and removes it from the linked list.
//
// removedReservation is used to save a copy
// before deleting the node.
bool ReservationManager::removeReservation(
    int reservationId,
    Reservation& removedReservation) {

    // If list is empty, nothing can be removed
    if (reservationHead == nullptr) {
        return false;
    }

    // current is used to move through the list
    ReservationNode* current =
        reservationHead;

    // previous remembers the node before current
    ReservationNode* previous =
        nullptr;

    // Search through linked list
    while (current != nullptr) {

        // Check if this is the reservation we want
        if (current->data.getReservationId()
            == reservationId) {

            // Save reservation before deleting node
            removedReservation =
                current->data;

            // If previous is nullptr,
            // we are deleting the first node
            if (previous == nullptr) {

                reservationHead =
                    current->next;
            }
            else {

                // Skip the current node
                // by connecting previous to next
                previous->next =
                    current->next;
            }

            // Free memory
            delete current;

            // One less active reservation
            reservationCount--;

            return true;
        }

        // Move previous forward
        previous = current;

        // Move current forward
        current = current->next;
    }

    // Reservation ID was not found
    return false;
}
// TRAVERSE RESERVATIONS
// "Traverse" means going through each node
// of the linked list one by one.
void ReservationManager::traverseReservations() const {

    // Start from first reservation
    ReservationNode* current =
        reservationHead;

    // Check if list is empty
    if (current == nullptr) {

        cout << "No reservations found." << endl;

        return;
    }

    // Go through all nodes
    while (current != nullptr) {

        // Display current reservation
        current->data.display();

        // Move to next reservation
        current = current->next;
    }
}
// ADD TO WAITING LIST
// The waiting list works as a QUEUE.
//
// FIFO = First In, First Out
//
// A new student is always added at the REAR.
void ReservationManager::addToWaitingList(
    int studentId,
    const string& studentName,
    const string& resourceId) {

    // Create a new waiting node
    WaitingNode* newNode =
        new WaitingNode;

    // Store student information
    newNode->studentId = studentId;
    newNode->studentName = studentName;
    newNode->resourceId = resourceId;

    // New node is currently the last node
    newNode->next = nullptr;

    // If waiting list is empty
    if (waitingRear == nullptr) {

        // New node becomes both
        // the front and rear
        waitingFront = newNode;
        waitingRear = newNode;
    }
    else {

        // Connect current last node
        // to the new node
        waitingRear->next = newNode;

        // New node becomes the new rear
        waitingRear = newNode;
    }

    // Increase number of waiting students
    waitingCount++;

    cout << studentName
         << " was added to the waiting list."
         << endl;
}

// REMOVE FROM WAITING LIST
// Removes the FIRST student from the queue.
//
// FIFO:
// First student added is the first student removed.
bool ReservationManager::removeFromWaitingList(
    WaitingNode*& removedNode) {

    // If queue is empty
    if (waitingFront == nullptr) {

        removedNode = nullptr;

        return false;
    }

    // Save the first node
    removedNode = waitingFront;

    // Move front to the next student
    waitingFront =
        waitingFront->next;

    // If there are no students left,
    // rear should also become nullptr
    if (waitingFront == nullptr) {

        waitingRear = nullptr;
    }

    // Disconnect removed node from the queue
    removedNode->next = nullptr;

    // One less student is waiting
    waitingCount--;

    return true;
}

// DISPLAY WAITING LIST
// Shows every student currently in the queue.
void ReservationManager::displayWaitingList() const {

    // Check if waiting list is empty
    if (waitingFront == nullptr) {

        cout << "Waiting list is empty." << endl;

        return;
    }

    cout << "\n--- Waiting List ---" << endl;

    // Start with first student
    WaitingNode* current =
        waitingFront;

    // Go through the queue
    while (current != nullptr) {

        cout << "Student ID: "
             << current->studentId << endl;

        cout << "Student Name: "
             << current->studentName << endl;

        cout << "Resource ID: "
             << current->resourceId << endl;

        cout << "--------------------"
             << endl;

        // Move to next student
        current = current->next;
    }
}

// PUSH CANCELLATION
// Adds a cancelled reservation to the TOP
// of the cancellation stack.
//
// Stack uses LIFO:
// Last In, First Out
void ReservationManager::pushCancellation(
    const Reservation& cancelledReservation) {

    // Create a new cancellation node
    CancellationNode* newNode =
        new CancellationNode;

    // Store the cancelled reservation
    newNode->data =
        cancelledReservation;

    // New node points to the current top
    newNode->next =
        cancellationTop;

    // New node becomes the new top
    cancellationTop =
        newNode;

    // Increase cancellation count
    cancellationCount++;
}

// RESTORE LAST CANCELLATION
// Restores the most recently cancelled reservation.
//
// Since cancellation history is a stack,
// the last cancelled reservation is restored first.
bool ReservationManager::restoreLastCancellation() {

    // Check if cancellation stack is empty
    if (cancellationTop == nullptr) {

        cout << "No cancelled reservations to restore."
             << endl;

        return false;
    }

    // Get the reservation stored at the top
    Reservation cancelledReservation =
        cancellationTop->data;

    // Find the resource for this reservation
    Resource* resource =
        findResource(
            cancelledReservation.getResourceId()
        );

    // Make sure resource still exists
    if (resource == nullptr) {

        cout << "Resource not found." << endl;

        return false;
    }

    // We can only restore if resource is available
    if (resource->availableQuantity <= 0) {

        cout << "Resource is not available."
             << endl;

        return false;
    }

    // Put reservation back into active
    // reservation linked list
    insertReservation(
        cancelledReservation
    );

    // The resource is being reserved again,
    // so decrease available quantity
    resource->availableQuantity--;

    // Save the current top node
    CancellationNode* temp =
        cancellationTop;

    // Move top down to next cancelled reservation
    cancellationTop =
        cancellationTop->next;

    // Delete old top node
    delete temp;

    // One less item in cancellation history
    cancellationCount--;

    cout << "Last cancelled reservation restored."
         << endl;

    return true;
}

// DISPLAY CANCELLATION HISTORY
// Goes through the cancellation stack and
// displays all cancelled reservations.
void ReservationManager::displayCancellationHistory() const {

    // Check if cancellation stack is empty
    if (cancellationTop == nullptr) {

        cout << "Cancellation history is empty."
             << endl;

        return;
    }

    cout << "\n--- Cancellation History ---"
         << endl;

    // Start at the top of the stack
    CancellationNode* current =
        cancellationTop;

    // Go through every cancellation
    while (current != nullptr) {

        // Display reservation information
        current->data.display();

        cout << "----------------------------"
             << endl;

        // Move to next node in stack
        current = current->next;
    }
}